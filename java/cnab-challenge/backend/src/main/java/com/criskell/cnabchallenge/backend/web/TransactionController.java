package com.criskell.cnabchallenge.backend.web;

import java.util.List;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.criskell.cnabchallenge.backend.entity.TransactionReport;
import com.criskell.cnabchallenge.backend.service.TransactionService;

@RestController
@RequestMapping("transactions")
public class TransactionController {
    private final TransactionService transactionService;

    public TransactionController(TransactionService transactionService) {
        this.transactionService = transactionService;
    }

    @GetMapping
    @CrossOrigin()
    List<TransactionReport> listAll() {
        return transactionService.listTransactionTotalsByStoreName();
    }
}
