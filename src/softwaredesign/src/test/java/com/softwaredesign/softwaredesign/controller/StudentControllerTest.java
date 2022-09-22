package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Student;
import com.softwaredesign.softwaredesign.entity.Subject;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
class StudentControllerTest {
    @Autowired
    private StudentController controller;

    @Test
    public void testAddStudent() {
        Student student = Student.builder()
                .firstName("Ahmad Khalid")
                .fatherName("Abdul Walid")
                .build();
        controller.addStudent(student);

        var studs = controller.getStudents();
        var student01 = studs.get(studs.size() - 1);

        Assertions.assertEquals(student.getFirstName(), student01.getFirstName());
        Assertions.assertEquals(student.getFatherName(), student01.getFatherName());

        controller.deleteStudent(student01);
    }

    @Test
    public void testGetStudentSubjects() {
        Subject subject = Subject.builder()
                .name("A22")
                .marks(22)
                .build();
        Student student = Student.builder()
                .firstName("Ahmad Khalid")
                .fatherName("Abdul Walid")
                .subjects(List.of(subject))
                .build();
        controller.addStudent(student);

        var studs = controller.getStudents();
        var student01 = studs.get(studs.size() - 1);

        Assertions.assertEquals(student01.getSubjects().get(0).getName(), subject.getName());

        controller.deleteStudent(student01);
    }
}