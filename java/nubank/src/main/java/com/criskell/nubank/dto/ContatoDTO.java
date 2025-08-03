package com.criskell.nubank.dto;

import jakarta.validation.constraints.NotBlank;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
public class ContatoDTO {

    @NotBlank(message = "E-mail é obrigatório!")
    private String email;

    @NotBlank(message = "Telefone é obrigatório!")
    private String telefone;

    private Long clienteId;
}
