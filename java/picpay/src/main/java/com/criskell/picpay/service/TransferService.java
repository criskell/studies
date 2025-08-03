package com.criskell.picpay.service;

import com.criskell.picpay.controller.dto.TransferDto;
import com.criskell.picpay.entity.Transfer;
import com.criskell.picpay.entity.Wallet;
import com.criskell.picpay.exception.InsufficientBalanceException;
import com.criskell.picpay.exception.TransferNotAllowedForWalletTypeException;
import com.criskell.picpay.exception.TransferNotAuthorizedException;
import com.criskell.picpay.exception.WalletNotFoundException;
import com.criskell.picpay.repository.TransferRepository;
import com.criskell.picpay.repository.WalletRepository;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

import java.util.concurrent.CompletableFuture;

@Service
public class TransferService {
    private final NotificationService notificationService;
    private final AuthorizationService authorizationService;
    private final TransferRepository transferRepository;
    private final WalletRepository walletRepository;

    public TransferService(NotificationService notificationService, AuthorizationService authorizationService, TransferRepository transferRepository, WalletRepository walletRepository) {
        this.notificationService = notificationService;
        this.authorizationService = authorizationService;
        this.transferRepository = transferRepository;
        this.walletRepository = walletRepository;
    }

    @Transactional
    public Transfer transfer(TransferDto transferDto) {
        var sender = walletRepository.findById(transferDto.payer())
                .orElseThrow(() -> new WalletNotFoundException(transferDto.payer()));

        var receiver = walletRepository.findById(transferDto.payee())
                .orElseThrow(() -> new WalletNotFoundException(transferDto.payee()));

        validateTransfer(transferDto, sender);

        sender.debit(transferDto.value());
        receiver.credit(transferDto.value());

        var transfer = new Transfer(sender, receiver, transferDto.value());

        walletRepository.save(sender);
        walletRepository.save(receiver);
        var transferResult = transferRepository.save(transfer);

        // The notification service may be unstable.
        CompletableFuture.runAsync(() -> notificationService.sendNotification(transferResult));

        return transferResult;
    }

    private void validateTransfer(TransferDto transferDto, Wallet sender) {
        if (!sender.isTransferAllowedForWalletType()) {
            throw new TransferNotAllowedForWalletTypeException();
        }

        if (!sender.isBalanceEqualOrGreaterThan(transferDto.value())) {
            throw new InsufficientBalanceException();
        }

        if (!authorizationService.isAuthorized(transferDto)) {
            throw new TransferNotAuthorizedException();
        }
    }
}
