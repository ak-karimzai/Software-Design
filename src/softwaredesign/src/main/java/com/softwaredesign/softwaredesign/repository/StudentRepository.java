package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.Student;
import com.softwaredesign.softwaredesign.entity.Subject;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface StudentRepository extends JpaRepository<Student, Long> {
    Student getByStudentId(Long id);
    @Modifying
    @Query(
            "delete from Subject s where s.subjectId = ?1"
    )
    void deleteSubject(Subject subject);
}
