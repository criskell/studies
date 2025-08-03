package com.criskell.nubank.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.criskell.nubank.model.Contato;

public interface ContatoRepository extends JpaRepository<Contato, Long> {
}
