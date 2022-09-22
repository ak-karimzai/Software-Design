package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.User;
import com.softwaredesign.softwaredesign.repository.UserRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class UserController {
    private UserRepository userRepository;

    public void addUser(String login,
                        String password,
                        String accessLevel) {
        User user = User.builder()
                .login(login)
                .password(password)
                .accessLevel(accessLevel)
                .build();
        userRepository.save(user);
    }

    public User getUser(Long id) {
        return userRepository.getUserByUserId(id);
    }

    public void addUser(User user) {
        userRepository.save(user);
    }

    public List<User> getAllUsers() {
        List<User> users =
                userRepository.findAll();
        return users;
    }

    public void updateUserAccessMode(@NotNull User user,
                                     String accessMode) {
        user.setAccessLevel(accessMode);
        userRepository.save(user);
    }

    public void updateUserPassword(@NotNull User user,
                                   String password) {
        user.setPassword(password);
        userRepository.save(user);
    }

    public List<User> getUsers() {
        return userRepository.findAll();
    }

    public void deleteUser(User user) {
        userRepository.delete(user);
    }

    public void deleteUser(Long id) {
        userRepository.deleteById(id);
    }
}
