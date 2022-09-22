package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Student;
import com.softwaredesign.softwaredesign.entity.Subject;
import com.softwaredesign.softwaredesign.repository.StudentRepository;
import lombok.AllArgsConstructor;
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
        Student student = Student.builder()
                .firstName(firstName)
                .fatherName(fatherName)
                .subjects(subjects)
                .build();
        studentRepository.save(student);
    }

    public void updateStudent(Student student) {
        studentRepository.save(student);
    }

    public void addSubject(Student student,
                           Subject newSubject) {
        student.getSubjects().add(newSubject);
        studentRepository.save(student);
    }

    public Student getStudent(Long id) {
        var student =
                studentRepository.getByStudentId(id);
        return student;
    }

    public void deleteStudentSubject(Student student,
                                     Subject subject) {
//        studentRepository.deleteSubjectByStudent(student.getStudentId(), subject.getName());
    }
}
