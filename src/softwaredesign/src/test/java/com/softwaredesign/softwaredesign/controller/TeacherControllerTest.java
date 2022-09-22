package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Teacher;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class TeacherControllerTest {
    @Autowired
    private TeacherController teacherController;

    @Test
    public void testAddTeacher() {
        Teacher teacher = Teacher.builder()
                .firstName("Ahmad Khalid")
                .lastName("Abdul Walid")
                .build();
        teacherController.addTeacher(teacher);

        var studs = teacherController.getTeachers();
        var student01 = studs.get(studs.size() - 1);

        Assertions.assertEquals(teacher.getFirstName(), student01.getFirstName());
        Assertions.assertEquals(teacher.getLastName(), student01.getLastName());

        teacherController.deleteTeacher(student01);
    }

    @Test
    public void testDeleteTeacher() {
        Teacher teacher = Teacher.builder()
                .firstName("Ahmad Khalid")
                .lastName("Abdul Walid")
                .build();
        teacherController.addTeacher(teacher);

        var teachers = teacherController.getTeachers();
        var teacher01 = teachers.get(teachers.size() - 1);

        int numberOfTechs = teachers.size();

        teacherController.deleteTeacher(teacher01);
        teachers = teacherController.getTeachers();

        int numberOfTechsAfterDeletion = teachers.size();

        Assertions.assertNotEquals(numberOfTechs, numberOfTechsAfterDeletion);
    }
}