package com.criskell.cbabchallenge.backend.entity;

import java.math.BigDecimal;

public record CnabTransaction(
        Integer type,
        String date,
        BigDecimal value,
        Long cpf,
        String card,
        String hour,
        String storeOwner,
        String storeName) {

}
