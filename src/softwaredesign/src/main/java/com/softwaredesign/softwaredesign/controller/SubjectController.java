package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Subject;
import com.softwaredesign.softwaredesign.repository.SubjectRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class SubjectController {
    SubjectRepository subjectRepository;

    public void addSubject(Subject subject) {
        subjectRepository.save(subject);
    }

    public void addSubject(String subName,
                           Integer marks) {
        Subject subject = Subject.builder()
                .name(subName)
                .marks(marks)
                .build();
        subjectRepository.save(subject);
    }

    public List<Subject> getSubjects() {
        return subjectRepository.findAll();
    }

    public void removeSubject(Long id) {
        subjectRepository.deleteById(id);
    }

    public void updateMarks(@NotNull Subject subject,
                            int marks) {
        subject.setMarks(marks);
        subjectRepository.save(subject);
    }

    public void updateSubject(Subject subject) {
        subjectRepository.save(subject);
    }

    public void deleteSubject(Subject subject) {
        subjectRepository.delete(subject);
    }

    public void deleteSubject(Long id) {
        subjectRepository.deleteById(id);
    }
}
