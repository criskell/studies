package com.criskell.picpay.client;

import com.criskell.picpay.client.dto.AuthorizationResponse;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;

@FeignClient(name = "AuthorizationClient", url = "${client.authorization-service.url}")
public interface AuthorizationClient {
    @GetMapping
    ResponseEntity<AuthorizationResponse> authorize();
}
