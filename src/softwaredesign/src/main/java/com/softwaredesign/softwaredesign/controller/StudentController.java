package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.entity.Student;
import com.softwaredesign.softwaredesign.entity.Subject;
import com.softwaredesign.softwaredesign.exception.DatabaseAccessException;
import com.softwaredesign.softwaredesign.repository.StudentRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.dao.DataAccessException;
import org.springframework.stereotype.Controller;

import java.util.ArrayList;
import java.util.List;

@Controller
@AllArgsConstructor
public class StudentController {
    private StudentRepository studentRepository;

    public void addStudent(String firstName,
                           String fatherName,
                           List<Subject> subjects) {
        try {
            Student student = Student.builder()
                    .firstName(firstName)
                    .fatherName(fatherName)
                    .subjects(subjects)
                    .build();
            studentRepository.save(student);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void addStudent(Student student) {
        try {
            studentRepository.save(student);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<Student> getStudents() {
        List<Student> students;
        try {
            students = studentRepository.findAll();
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return students;
    }

    public void updateStudent(Student student) {
        try {
            studentRepository.save(student);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void addSubject(@NotNull Student student,
                           Subject newSubject) {
        try {
            var subjects = new ArrayList<>(student.getSubjects());
            subjects.add(newSubject);
            student.setSubjects(subjects);
            studentRepository.save(student);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }

    }

    public void deleteStudent(Student student) {
        try {
            studentRepository.delete(student);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public Student getStudent(Long id) {
        Student student;
        try {
            student = studentRepository.getByStudentId(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return student;
    }

    public void changeStudentGroup(@NotNull Student student, Group newGroup) {
        try {
            student.setGroup(newGroup);
            studentRepository.save(student);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<Subject> getStudentSubjects(@NotNull Student student) {
        List<Subject> subjects;
        try {
            subjects = student.getSubjects();
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return subjects;
    }
}
