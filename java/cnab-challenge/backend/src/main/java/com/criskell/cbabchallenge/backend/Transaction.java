package com.criskell.cbabchallenge.backend;

import java.math.BigDecimal;
import java.sql.Date;
import java.sql.Time;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public record Transaction(
        Long id,
        Integer type,
        Date date,
        BigDecimal value,
        Long cpf,
        String card,
        Time hour,
        String storeOwner,
        String storeName
        ) {

    // N.B.: "Wither pattern"
    public Transaction withValue(BigDecimal value) {
        return new Transaction(
                this.id(),
                this.type(),
                this.date(),
                value,
                this.cpf(),
                this.card(),
                this.hour(),
                this.storeOwner().trim(),
                this.storeName().trim()
        );
    }

    public Transaction withDate(String date) throws ParseException {
        var dateFormat = new SimpleDateFormat("yyyyMMdd");
        var parsedDate = dateFormat.parse(date);

        return new Transaction(
                this.id(),
                this.type(),
                new Date(parsedDate.getTime()),
                this.value(),
                this.cpf(),
                this.card(),
                this.hour(),
                this.storeOwner().trim(),
                this.storeName().trim()
        );
    }

    public Transaction withHour(String date) throws ParseException {
        var dateFormat = new SimpleDateFormat("HHmmss");
        var parsedDate = dateFormat.parse(date);

        return new Transaction(
                this.id(),
                this.type(),
                this.date(),
                this.value(),
                this.cpf(),
                this.card(),
                new Time(parsedDate.getTime()),
                this.storeOwner().trim(),
                this.storeName().trim()
        );
    }
}
