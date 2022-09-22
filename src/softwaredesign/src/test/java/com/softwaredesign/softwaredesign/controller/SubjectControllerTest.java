package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Subject;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class SubjectControllerTest {
    @Autowired
    private SubjectController subjectController;

    @Test
    public void testAddSubject() {
        Subject subject = Subject.builder()
                .name("math")
                .marks(30)
                .build();
        subjectController.addSubject(subject);

        var subjects = subjectController.getSubjects();
        var lastSubject = subjects.get(subjects.size() - 1);

        Assertions.assertEquals(lastSubject.getName(), "math");
        Assertions.assertEquals(lastSubject.getMarks(), 30);

        subjectController.deleteSubject(lastSubject);
    }

    @Test
    public void updateSubject() {
        Subject subject = Subject.builder()
                .name("physics")
                .marks(36)
                .build();
        subjectController.addSubject(subject);

        var subjects = subjectController.getSubjects();
        var lastSubject = subjects.get(subjects.size() - 1);

        Assertions.assertEquals(lastSubject.getName(), "physics");
        Assertions.assertEquals(lastSubject.getMarks(), 36);

        subjectController.deleteSubject(lastSubject);

        lastSubject = subjects.get(subjects.size() - 1);
        Assertions.assertEquals(lastSubject.getName(), "physics");
        Assertions.assertEquals(lastSubject.getMarks(), 36);
    }
}