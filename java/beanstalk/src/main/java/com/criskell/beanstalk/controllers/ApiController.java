package com.criskell.beanstalk.controllers;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import com.criskell.beanstalk.dto.ApiResponse;

@RestController
public class ApiController {
    @GetMapping
    public ResponseEntity<ApiResponse> helloAws() {
        return ResponseEntity.ok(new ApiResponse("Hello AWS! Updated"));
    }    
}
