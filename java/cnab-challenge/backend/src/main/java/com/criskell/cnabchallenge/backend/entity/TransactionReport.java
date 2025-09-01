package com.criskell.cnabchallenge.backend.entity;

import java.math.BigDecimal;
import java.util.List;

public record TransactionReport(String storeName, BigDecimal total, List<Transaction> transactions) {
    public TransactionReport addTotal(BigDecimal value) {
        return new TransactionReport(storeName, total.add(value), transactions);
    }

    public TransactionReport addTransaction(Transaction transaction) {
        transactions.add(transaction);
        return new TransactionReport(storeName, total, transactions);
    }
}
