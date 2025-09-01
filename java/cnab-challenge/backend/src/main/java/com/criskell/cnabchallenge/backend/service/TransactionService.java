package com.criskell.cnabchallenge.backend.service;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

import org.springframework.stereotype.Service;

import com.criskell.cnabchallenge.backend.entity.TransactionReport;
import com.criskell.cnabchallenge.backend.repository.TransactionRepository;

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
            BigDecimal value = transaction.value();

            reportMap.compute(storeName, (key, existingReport) -> {
                var report = (existingReport != null) ? existingReport
                        : new TransactionReport(key, BigDecimal.ZERO, new ArrayList<>());

                return report.addTotal(value).addTransaction(transaction.withValue(value));
            });
        });

        return new ArrayList<>(reportMap.values());
    }
}
