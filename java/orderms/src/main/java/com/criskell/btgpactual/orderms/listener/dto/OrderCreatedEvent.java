package com.criskell.btgpactual.orderms.listener.dto;

import com.fasterxml.jackson.annotation.JsonProperty;

import java.util.List;

public record OrderCreatedEvent(
        @JsonProperty("codigoPedido") Long orderCode,
        @JsonProperty("codigoCliente") Long customerCode,
        @JsonProperty("itens") List<OrderItemEvent> items
) {
}
