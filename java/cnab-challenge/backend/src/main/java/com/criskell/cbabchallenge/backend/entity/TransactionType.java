package com.criskell.cbabchallenge.backend.entity;

import java.math.BigDecimal;

public enum TransactionType {
    DEBIT(1),
    BOLETO(2),
    FINANCING(3),
    CREDIT(4),
    LOAN_RECEIPT(5),
    SALES(6),
    TED_RECEIPT(7),
    DOC_RECEIPT(8),
    RENT(9);

    private int type;

    private TransactionType(int type) {
        this.type = type;
    }

    public BigDecimal getSign() {
        return switch (type) {
            case 1, 4, 5, 6, 7, 8 -> new BigDecimal(1);
            case 2, 3, 9 -> new BigDecimal(-1);
            default -> new BigDecimal(0);
        };
    }

    public static TransactionType findByType(int type) {
        for (TransactionType transactionType : values()) {
            if (transactionType.type == type) {
                return transactionType;
            }
        }

        throw new IllegalArgumentException("Invalid type: " + type);
    }
}
