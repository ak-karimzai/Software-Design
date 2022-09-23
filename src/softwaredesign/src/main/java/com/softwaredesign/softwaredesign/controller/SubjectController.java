package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Subject;
import com.softwaredesign.softwaredesign.exception.DatabaseAccessException;
import com.softwaredesign.softwaredesign.repository.SubjectRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.dao.DataAccessException;
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
        try {
            Subject subject = Subject.builder()
                .name(subName)
                .marks(marks)
                .build();
            subjectRepository.save(subject);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<Subject> getSubjects() {
        List<Subject> subjects;
        try {
            subjects = subjectRepository.findAll();
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return subjects;
    }

    public void removeSubject(Long id) {
        try {
            subjectRepository.deleteById(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void updateMarks(@NotNull Subject subject,
                            int marks) {
        try {
            subject.setMarks(marks);
            subjectRepository.save(subject);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void updateSubject(Subject subject) {
        try {
            subjectRepository.save(subject);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void deleteSubject(Subject subject) {
        try {
            subjectRepository.delete(subject);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void deleteSubject(Long id) {
        try {
            subjectRepository.deleteById(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }
}
