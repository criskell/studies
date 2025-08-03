package com.criskell.picpay.service;

import com.criskell.picpay.controller.dto.CreateWalletDto;
import com.criskell.picpay.entity.Wallet;
import com.criskell.picpay.exception.WalletDataAlreadyExistsException;
import com.criskell.picpay.repository.WalletRepository;
import org.springframework.stereotype.Service;

@Service
public class WalletService {
    private final WalletRepository walletRepository;

    public WalletService(WalletRepository walletRepository) {
        this.walletRepository = walletRepository;
    }

    public Wallet createWallet(CreateWalletDto dto) {
        var walletFromDatabase = walletRepository.findByCpfCnpjOrEmail(dto.cpfCnpj(), dto.email());

        if (walletFromDatabase.isPresent()) {
            throw new WalletDataAlreadyExistsException("CpfCnpj of Email already exists");
        }

        return walletRepository.save(dto.toWallet());
    }
}
