package com.criskell.picpay.service;

import com.criskell.picpay.client.AuthorizationClient;
import com.criskell.picpay.controller.dto.TransferDto;
import com.criskell.picpay.entity.Transfer;
import com.criskell.picpay.exception.PicPayException;
import org.springframework.stereotype.Service;

@Service
public class AuthorizationService {
    private final AuthorizationClient authorizationClient;

    public AuthorizationService(AuthorizationClient authorizationClient) {
        this.authorizationClient = authorizationClient;
    }

    public boolean isAuthorized(TransferDto transfer) {
        var response = authorizationClient.authorize();

        if (response.getStatusCode().isError()) {
            throw new PicPayException();
        }

        return response.getBody().data().authorization();
    }
}
