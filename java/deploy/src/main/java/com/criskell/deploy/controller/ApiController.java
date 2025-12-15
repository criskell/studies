package com.criskell.deploy.controller;

import java.time.Instant;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import com.criskell.deploy.dto.TimestampResponse;

@RestController
public class ApiController {
    @GetMapping
    public ResponseEntity<TimestampResponse> helloAws() {
        return ResponseEntity.ok(new TimestampResponse(Instant.now()));
    }    
}
