package com.criskell.picpay.client.dto;

public record AuthorizationResponse(String status, AuthorizationData data) {
    public record AuthorizationData(boolean authorization) {}
}
