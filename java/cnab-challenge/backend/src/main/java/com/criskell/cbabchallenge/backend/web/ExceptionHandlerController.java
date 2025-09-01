package com.criskell.cbabchallenge.backend.web;

import org.springframework.batch.core.repository.JobInstanceAlreadyCompleteException;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;

@ControllerAdvice
public class ExceptionHandlerController {
    @ExceptionHandler(JobInstanceAlreadyCompleteException.class)
    public ResponseEntity<Object> handleFileAlreadyImported(JobInstanceAlreadyCompleteException exception) {
        return ResponseEntity.status(HttpStatus.CONFLICT)
                .body("The file provided has already been imported into the system");
    }
}
