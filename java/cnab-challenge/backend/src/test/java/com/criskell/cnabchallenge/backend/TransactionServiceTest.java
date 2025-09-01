package com.criskell.cnabchallenge.backend;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.mockito.Mockito.when;

import java.math.BigDecimal;
import java.sql.Time;
import java.util.List;
import java.sql.Date;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import com.criskell.cnabchallenge.backend.entity.Transaction;
import com.criskell.cnabchallenge.backend.repository.TransactionRepository;
import com.criskell.cnabchallenge.backend.service.TransactionService;

@ExtendWith(MockitoExtension.class)
public class TransactionServiceTest {
    @InjectMocks
    private TransactionService transactionService;

    @Mock
    private TransactionRepository transactionRepository;

    @Test
    public void testListTransactionTotalsByStoreName() {
        // AAA
        // Arrange
        final String storeA = "Store A", storeB = "Store B";

        var transaction1 = new Transaction(
                1L,
                1,
                new Date(System.currentTimeMillis()),
                BigDecimal.valueOf(100),
                123456789L,
                "1234-5678-9012-3456",
                new Time(System.currentTimeMillis()),
                "Store A Owner",
                storeA);

        var transaction2 = new Transaction(
                2L,
                1,
                new Date(System.currentTimeMillis()),
                BigDecimal.valueOf(50.00),
                987654321L,
                "9876-5432-1098-7654",
                new Time(System.currentTimeMillis()),
                "Store B Owner",
                storeB);

        var transaction3 = new Transaction(
                3L,
                1,
                new Date(System.currentTimeMillis()),
                BigDecimal.valueOf(75.00),
                111222333L,
                "1111-2222-3333-4444",
                new Time(System.currentTimeMillis()),
                "Store A Owner",
                storeA);

        // Stub - Simulate what is returned when the mock method is invoked
        var mockTransactions = List.of(transaction1, transaction2, transaction3);

        when(transactionRepository.findAllByOrderByStoreNameAscIdDesc()).thenReturn(mockTransactions);

        // Act
        var reports = transactionService.listTransactionTotalsByStoreName();

        // Assert
        assertEquals(2, reports.size());

        reports.forEach(report -> {
            if (report.storeName().equals(storeA)) {
                assertEquals(2, report.transactions().size());
                assertEquals(BigDecimal.valueOf(175.0), report.total());
                assertTrue(report.transactions().contains(transaction1));
                assertTrue(report.transactions().contains(transaction3));
            }

            if (report.storeName().equals(storeB)) {
                assertEquals(1, report.transactions().size());
                assertEquals(BigDecimal.valueOf(50.0), report.total());
                assertTrue(report.transactions().contains(transaction2));
            }
        });
    }
}
