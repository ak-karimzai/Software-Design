package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.entity.Teacher;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class TeacherRepositoryTest {
    @Autowired
    private TeacherRepository teacherRepository;

    @Test
    public void saveTeacher() {
        Group group = Group.builder()
                .name("A12")
                .numberOfStudents(20)
                .build();
        Teacher teacher =
                Teacher.builder()
                        .firstName("Ahmad Khalid")
                        .lastName("Karimzai")
                        .groups(List.of(group))
                        .build();
        teacherRepository.save(teacher);
    }
}