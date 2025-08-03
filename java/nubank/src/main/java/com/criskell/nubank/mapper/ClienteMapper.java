package com.criskell.nubank.mapper;

import java.util.List;
import java.util.stream.Collectors;

import com.criskell.nubank.dto.ClientesResponseDTO;
import com.criskell.nubank.dto.ContatoResponseDTO;
import com.criskell.nubank.model.Clientes;

public class ClienteMapper {

    public static ClientesResponseDTO toDTO(Clientes cliente) {
        ClientesResponseDTO dto = new ClientesResponseDTO();
        dto.setId(cliente.getId());
        dto.setNome(cliente.getNome());

        List<ContatoResponseDTO> contatos = cliente.getContatos().stream().map(contato -> {
            ContatoResponseDTO contatoResponseDTO = new ContatoResponseDTO();
            contatoResponseDTO.setId(contato.getId());
            contatoResponseDTO.setTelefone(contato.getTelefone());
            contatoResponseDTO.setEmail(contato.getEmail());
            return contatoResponseDTO;
        }).collect(Collectors.toList());

        dto.setContatos(contatos);

        return dto;
    }
}
