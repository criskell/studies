package com.criskell.cnabchallenge.backend.entity;

import java.math.BigDecimal;
import java.sql.Date;
import java.sql.Time;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import org.springframework.data.annotation.Id;
import org.springframework.data.relational.core.mapping.Column;

public record Transaction(
        @Id Long id,
        Integer type,
        Date date,
        BigDecimal value,
        Long cpf,
        String card,
        Time hour,
        @Column("store_owner") String storeOwner,
        @Column("store_name") String storeName) {

    // N.B.: "Wither pattern"
    public Transaction withValue(BigDecimal value) {
        return new Transaction(
                id,
                type,
                date,
                value,
                cpf,
                card,
                hour,
                storeOwner,
                storeName);
    }

    public Transaction withDate(String date) throws ParseException {
        var dateFormat = new SimpleDateFormat("yyyyMMdd");
        var parsedDate = dateFormat.parse(date);

        return new Transaction(
                id,
                type,
                new Date(parsedDate.getTime()),
                value,
                cpf,
                card,
                hour,
                storeOwner,
                storeName);
    }

    public Transaction withHour(String date) throws ParseException {
        var dateFormat = new SimpleDateFormat("HHmmss");
        var parsedDate = dateFormat.parse(date);

        return new Transaction(
                id,
                type,
                this.date,
                value,
                cpf,
                card,
                new Time(parsedDate.getTime()),
                storeOwner,
                storeName);
    }
}
