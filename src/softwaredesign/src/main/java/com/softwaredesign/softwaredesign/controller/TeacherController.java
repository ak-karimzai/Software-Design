package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.entity.Teacher;
import com.softwaredesign.softwaredesign.exception.DatabaseAccessException;
import com.softwaredesign.softwaredesign.repository.TeacherRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.dao.DataAccessException;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class TeacherController {
    private TeacherRepository teacherRepository;

    public void addTeacher(String firstName,
                           String lastName) {
        try {
            Teacher teacher = Teacher.builder()
                    .firstName(firstName)
                    .lastName(lastName)
                    .build();
            teacherRepository.save(teacher);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void addTeacher(Teacher teacher) {
        try {
            teacherRepository.save(teacher);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void updateTeacher(Teacher teacher) {
        try {
            teacherRepository.save(teacher);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void addGroup(@NotNull Teacher teacher,
                         @NotNull Group newGroup) {
        try {
            teacher.getGroups().add(newGroup);
            teacherRepository.save(teacher);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<Teacher> getTeachers() {
        List<Teacher> teachers;
        try {
            teachers = teacherRepository.findAll();
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return teachers;
    }

    public Teacher getTeacher(Long id) {
        Teacher teacher;
        try {
            teacher = teacherRepository.getTeacherByTeacherId(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return teacher;
    }

    public void deleteTeacher(Long id) {
        try {
            teacherRepository.deleteById(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void deleteTeacher(Teacher teacher) {
        try {
            teacherRepository.delete(teacher);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }
}
