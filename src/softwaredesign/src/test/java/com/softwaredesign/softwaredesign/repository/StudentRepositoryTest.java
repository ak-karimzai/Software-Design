package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.Student;
import com.softwaredesign.softwaredesign.entity.Subject;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
class StudentRepositoryTest {
    @Autowired
    private StudentRepository studentRepository;

    @Test
    public void testAddStudent() {
        Subject subject = Subject.builder()
                .name("math")
                .marks(24)
                .build();
        Subject subject01 = Subject.builder()
                .name("physics")
                .marks(34)
                .build();
        Student student = Student.builder()
                .firstName("Ahmad")
                .fatherName("mumtaz")
                .subjects(List.of(subject, subject01))
                .build();
        studentRepository.save(student);
    }

    @Test
    public void testGetStudentById() {
        Subject subject = Subject.builder()
                .name("math")
                .marks(24)
                .build();
        Subject subject01 = Subject.builder()
                .name("physics")
                .marks(34)
                .build();
        Student student = Student.builder()
                .firstName("Ahmad")
                .fatherName("mumtaz")
                .subjects(List.of(subject, subject01))
                .build();
        studentRepository.save(student);

        var students = studentRepository.findAll();
        var lastAddedStudent = students.get(students.size() - 1);

        var studentGetByid = studentRepository.getByStudentId(lastAddedStudent.getStudentId());

        Assertions.assertEquals(lastAddedStudent.getFirstName(), studentGetByid.getFirstName());
        Assertions.assertEquals(lastAddedStudent.getFatherName(), studentGetByid.getFatherName());

        studentRepository.delete(studentGetByid);
    }
}