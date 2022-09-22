package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Subject;
import com.softwaredesign.softwaredesign.repository.SubjectRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Controller;

@Controller
@AllArgsConstructor
public class SubjectController {
    SubjectRepository subjectRepository;

    public void removeSubject(Long id) {
        subjectRepository.deleteById(id);
    }

    public void updateMarks(Subject subject,
                              int marks) {
        subject.setMarks(marks);
        subjectRepository.save(subject);
    }

    public void updateSubject(Subject subject) {
        subjectRepository.save(subject);
    }
}
