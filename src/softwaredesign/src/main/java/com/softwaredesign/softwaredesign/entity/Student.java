package com.softwaredesign.softwaredesign.entity;

import lombok.*;

import javax.persistence.*;
import java.util.List;

@Data
@Entity
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Student {
    @Id
    @SequenceGenerator(
            name = "student_sequence",
            sequenceName = "student_sequence",
            allocationSize = 1
    )
    @GeneratedValue(
            strategy = GenerationType.SEQUENCE,
            generator = "student_sequence"
    )
    private Long studentId;
    private String firstName;
    private String fatherName;
    @OneToOne
    @JoinColumn(
            name = "group_id",
            referencedColumnName = "groupId"
    )
    private Group group;
    @OneToMany(
            cascade = CascadeType.ALL
    )
    @JoinColumn(
            name = "student_id",
            referencedColumnName = "studentId"
    )
    private List<Subject> subjects;
}
