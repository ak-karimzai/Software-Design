package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.entity.Teacher;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TeacherRepository extends JpaRepository<Teacher, Long> {
    Teacher getTeacherByFirstName(String name);
    Teacher getTeacherByTeacherId(Long id);
}
