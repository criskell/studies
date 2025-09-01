package com.criskell.cnabchallenge.backend.web;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.criskell.cnabchallenge.backend.service.CnabService;

@RestController
@RequestMapping("cnab")
public class CnabController {
    private final CnabService cnabService;

    public CnabController(CnabService cnabService) {
        this.cnabService = cnabService;
    }

    @PostMapping("upload")
    @CrossOrigin()
    public String upload(@RequestParam("file") MultipartFile file) throws Exception {
        cnabService.uploadCnabFile(file);

        return "Background processing initialized";
    }
}
