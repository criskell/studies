package com.criskell.nubank.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.criskell.nubank.model.Clientes;

public interface ClientesRepository extends JpaRepository<Clientes, Long> {
}
