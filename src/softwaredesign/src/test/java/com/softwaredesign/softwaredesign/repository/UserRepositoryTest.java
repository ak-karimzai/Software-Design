package com.softwaredesign.softwaredesign.repository;

import com.softwaredesign.softwaredesign.entity.User;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class UserRepositoryTest {
    @Autowired
    private UserRepository userRepository;

    @Test
    public void checkAddUser() {
        User user = User.builder()
                .login("math")
                .password("math")
                .build();
        userRepository.save(user);

        var users = userRepository.findAll();
        var lastAddedUser = users.get(users.size() - 1);

        Assertions.assertEquals(user.getLogin(), lastAddedUser.getLogin());
        Assertions.assertEquals(user.getPassword(), lastAddedUser.getPassword());

        userRepository.delete(user);
    }

    @Test
    public void checkGetAllUsers() {
        var users = userRepository.findAll();

        User user = User.builder()
                .login("math")
                .password("math")
                .build();
        userRepository.save(user);

        var usersAfterNewAdd = userRepository.findAll();
        Assertions.assertNotEquals(users.size(), usersAfterNewAdd.size());

        userRepository.delete(user);
    }
}