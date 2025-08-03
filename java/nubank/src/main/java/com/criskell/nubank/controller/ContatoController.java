package com.criskell.nubank.controller;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.criskell.nubank.dto.ContatoDTO;
import com.criskell.nubank.model.Clientes;
import com.criskell.nubank.model.Contato;
import com.criskell.nubank.repository.ClientesRepository;
import com.criskell.nubank.repository.ContatoRepository;

import jakarta.validation.Valid;

@RestController
@RequestMapping("/contatos")
public class ContatoController {

    @Autowired
    private ContatoRepository contatoRepository;

    @Autowired
    private ClientesRepository clientesRepository;

    @PostMapping
    public ResponseEntity<?> criar(@RequestBody @Valid ContatoDTO dto) {
        Optional<Clientes> optionalClientes = clientesRepository.findById(dto.getClienteId());

        if (optionalClientes.isEmpty()) {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Cliente não encontrado");
        }

        Contato contato = new Contato();
        contato.setTelefone(dto.getTelefone());
        contato.setEmail(dto.getEmail());
        contato.setClientes(optionalClientes.get());

        contatoRepository.save(contato);

        return ResponseEntity.status(HttpStatus.CREATED).body(contato);
    }
}
