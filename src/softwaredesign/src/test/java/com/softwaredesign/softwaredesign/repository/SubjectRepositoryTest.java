package com.softwaredesign.softwaredesign.repository;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class SubjectRepositoryTest {
    @Autowired
    private SubjectRepository subjectRepository;
    @Test
    public void checkDelete() {
//        subjectRepository.deleteById(id);
    }
}