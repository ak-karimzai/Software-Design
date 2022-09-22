package com.softwaredesign.softwaredesign.entity;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;

@Entity(name = "tbl_user")
@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class User {
    public enum LEVEL {
        ADMIN,
        TEACHER,
        STUDENT
    }
    @Id
    @SequenceGenerator(
            name = "user_login_sequence",
            sequenceName = "user_login_sequence",
            allocationSize = 1
    )
    @GeneratedValue(
            strategy = GenerationType.SEQUENCE,
            generator = "user_login_sequence"
    )
    private Long userId;
    private String login;
    private String password;
    private String accessLevel;
}
