package com.criskell.cbabchallenge.backend.repository;

import java.util.List;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.criskell.cbabchallenge.backend.entity.Transaction;

@Repository
public interface TransactionRepository extends CrudRepository<Transaction, Long> {
    List<Transaction> findAllByOrderByStoreNameAscIdDesc();
}
