package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.User;
import com.softwaredesign.softwaredesign.repository.UserRepository;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
public class UserController {
    UserRepository userRepository;

    public void addUser(String login,
                        String password,
                        User.LEVEL accessLevel) {
        User user = User.builder()
                .login(login)
                .password(password)
                .accessLevel(accessLevel)
                .build();
        userRepository.save(user);
    }

    public List<User> getAllUsers() {
        List<User> users =
                userRepository.findAll();
        return users;
    }

    public void updateUserAccessMode(User user,
                                     User.LEVEL accessMode) {
        user.setAccessLevel(accessMode);
        userRepository.save(user);
    }

    public void updateUserPassword(User user,
                                     String password) {
        user.setPassword(password);
        userRepository.save(user);
    }
}
