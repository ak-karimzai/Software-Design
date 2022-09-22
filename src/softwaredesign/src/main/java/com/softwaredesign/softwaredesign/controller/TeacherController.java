package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.entity.Teacher;
import com.softwaredesign.softwaredesign.repository.TeacherRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class TeacherController {
    private TeacherRepository teacherRepository;

    public void addTeacher(String firstName,
                           String lastName) {
        Teacher teacher = Teacher.builder()
                .firstName(firstName)
                .lastName(lastName)
                .build();
        teacherRepository.save(teacher);
    }

    public void addTeacher(Teacher teacher) {
        teacherRepository.save(teacher);
    }

    public void updateTeacher(Teacher teacher) {
        teacherRepository.save(teacher);
    }

    public void addGroup(Teacher teacher,
                         Group newGroup) {
        teacher.getGroups().add(newGroup);
        teacherRepository.save(teacher);
    }

    public List<Teacher> getTeachers() {
        List<Teacher> teachers =
                teacherRepository.findAll();
        return teachers;
    }

    public Teacher getTeacher(Long id) {
        Teacher teacher =
                teacherRepository.getTeacherByTeacherId(id);
        return teacher;
    }

    public void deleteTeacher(Long id) {
        teacherRepository.deleteById(id);
    }

    public void deleteTeacher(Teacher teacher) {
        teacherRepository.delete(teacher);
    }
}
