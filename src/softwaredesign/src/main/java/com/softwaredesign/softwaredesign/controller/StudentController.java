package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.entity.Student;
import com.softwaredesign.softwaredesign.entity.Subject;
import com.softwaredesign.softwaredesign.repository.StudentRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.stereotype.Controller;

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

    public void addStudent(Student student) {
        studentRepository.save(student);
    }

    public List<Student> getStudents() {
        return studentRepository.findAll();
    }

    public void updateStudent(Student student) {
        studentRepository.save(student);
    }

    public void addSubject(@NotNull Student student,
                           Subject newSubject) {
        student.getSubjects().add(newSubject);
        studentRepository.save(student);
    }

    public void deleteStudent(Student student) {
        studentRepository.delete(student);
    }

    public Student getStudent(Long id) {
        var student =
                studentRepository.getByStudentId(id);
        return student;
    }

    public void changeStudentGroup(@NotNull Student student, Group newGroup) {
        student.setGroup(newGroup);
        studentRepository.save(student);
    }

    public List<Subject> getStudentSubjects(@NotNull Student student) {
        return student.getSubjects();
    }
}
