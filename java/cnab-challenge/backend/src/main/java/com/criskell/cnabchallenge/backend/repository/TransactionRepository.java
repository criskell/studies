package com.criskell.cnabchallenge.backend.repository;

import java.util.List;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.criskell.cnabchallenge.backend.entity.Transaction;

@Repository
public interface TransactionRepository extends CrudRepository<Transaction, Long> {
    List<Transaction> findAllByOrderByStoreNameAscIdDesc();
}
