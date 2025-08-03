package com.criskell.nubank.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.criskell.nubank.dto.ClientesDTO;
import com.criskell.nubank.dto.ClientesResponseDTO;
import com.criskell.nubank.dto.ContatoResponseDTO;
import com.criskell.nubank.model.Clientes;
import com.criskell.nubank.service.ClientesService;

@RestController
@RequestMapping("/clientes")
public class ClienteController {

    @Autowired
    private ClientesService clientesService;

    @PostMapping
    public ResponseEntity<Clientes> criar(@RequestBody ClientesDTO dto) {
        Clientes cliente = clientesService.salvarCliente(dto);

        return ResponseEntity.status(HttpStatus.CREATED).body(cliente);
    }

    @GetMapping
    public ResponseEntity<List<ClientesResponseDTO>> listarTodos() {
        return ResponseEntity.ok(clientesService.listarTodos());
    }

    @GetMapping("/{id}/contatos")
    public ResponseEntity<List<ContatoResponseDTO>> listarContatos(@PathVariable Long id) {
        return ResponseEntity.ok(clientesService.listarContatosPorCliente(id));
    }
}
