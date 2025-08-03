package com.criskell.nubank.service;

import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.criskell.nubank.dto.ClientesDTO;
import com.criskell.nubank.dto.ClientesResponseDTO;
import com.criskell.nubank.dto.ContatoResponseDTO;
import com.criskell.nubank.mapper.ClienteMapper;
import com.criskell.nubank.model.Clientes;
import com.criskell.nubank.model.Contato;
import com.criskell.nubank.repository.ClientesRepository;

@Service
public class ClientesService {

    @Autowired
    private ClientesRepository clientesRepository;

    public Clientes salvarCliente(ClientesDTO dto) {
        Clientes clientes = new Clientes();
        clientes.setNome(dto.getNome());

        if (dto.getContatos() != null && !dto.getContatos().isEmpty()) {
            List<Contato> contatos = dto.getContatos().stream().map(contatoDTO -> {
                Contato contato = new Contato();
                contato.setTelefone(contatoDTO.getTelefone());
                contato.setEmail(contatoDTO.getEmail());
                contato.setClientes(clientes);
                return contato;
            }).collect(Collectors.toList());

            clientes.setContatos(contatos);
        }

        return clientesRepository.save(clientes);
    }

    public List<ClientesResponseDTO> listarTodos() {
        return clientesRepository.findAll().stream().map(ClienteMapper::toDTO).collect(Collectors.toList());
    }

    public List<ContatoResponseDTO> listarContatosPorCliente(Long clienteId) {
        Clientes cliente = clientesRepository.findById(clienteId).orElseThrow(() -> new RuntimeException("Cliente não encontrado"));

        return cliente.getContatos().stream().map(contato -> {
            ContatoResponseDTO contatoResponseDTO = new ContatoResponseDTO();
            contatoResponseDTO.setId(contato.getId());
            contatoResponseDTO.setTelefone(contato.getTelefone());
            contatoResponseDTO.setEmail(contato.getEmail());
            contatoResponseDTO.setClienteId(clienteId);
            return contatoResponseDTO;
        }).collect(Collectors.toList());
    }
}
