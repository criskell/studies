package com.criskell.cbabchallenge.backend.service;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

import org.springframework.stereotype.Service;

import com.criskell.cbabchallenge.backend.entity.TransactionReport;
import com.criskell.cbabchallenge.backend.entity.TransactionType;
import com.criskell.cbabchallenge.backend.repository.TransactionRepository;

@Service
public class TransactionService {
    private final TransactionRepository transactionRepository;

    public TransactionService(TransactionRepository transactionRepository) {
        this.transactionRepository = transactionRepository;
    }

    public List<TransactionReport> listTransactionTotalsByStoreName() {
        var transactions = transactionRepository.findAllByOrderByStoreNameAscIdDesc();
        var reportMap = new LinkedHashMap<String, TransactionReport>(); // LinkedHashMap preserves order.

        transactions.forEach(transaction -> {
            String storeName = transaction.storeName();
            var transactionType = TransactionType.findByType(transaction.type());
            BigDecimal value = transaction.value().multiply(transactionType.getSign());

            reportMap.compute(storeName, (key, existingReport) -> {
                var report = (existingReport != null) ? existingReport
                        : new TransactionReport(key, BigDecimal.ZERO, new ArrayList<>());

                return report.addTotal(value).addTransaction(transaction.withValue(value));
            });
        });

        return new ArrayList<>(reportMap.values());
    }
}
