package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.Subject;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class SubjectRepositoryTest {
    @Autowired
    private SubjectRepository subjectRepository;
    @Test
    public void checkAddSubject() {
        Subject subject = Subject.builder()
                .name("math")
                .marks(35)
                .build();
        subjectRepository.save(subject);

        var subjects = subjectRepository.findAll();
        var lastAddedSubject = subjects.get(subjects.size() - 1);

        Assertions.assertEquals(subject.getName(), lastAddedSubject.getName());
        Assertions.assertEquals(subject.getMarks(), lastAddedSubject.getMarks());

        subjectRepository.delete(subject);
    }

    @Test
    public void checkGetAllSubjects() {
        var subjects = subjectRepository.findAll();

        Subject subject = Subject.builder()
                .name("math")
                .marks(35)
                .build();
        subjectRepository.save(subject);

        var subjectsAfterNewAdd = subjectRepository.findAll();
        Assertions.assertNotEquals(subjects.size(), subjectsAfterNewAdd.size());

        subjectRepository.delete(subject);
    }
}