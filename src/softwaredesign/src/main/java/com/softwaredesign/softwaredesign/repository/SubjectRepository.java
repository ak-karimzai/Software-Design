package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.Subject;
import org.springframework.data.jpa.repository.JpaRepository;


public interface SubjectRepository extends JpaRepository<Subject, Long> {
}
