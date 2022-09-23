package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.User;
import com.softwaredesign.softwaredesign.exception.DatabaseAccessException;
import com.softwaredesign.softwaredesign.repository.UserRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.dao.DataAccessException;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class UserController {
    private UserRepository userRepository;

    public void addUser(String login,
                        String password,
                        String accessLevel) {
        try {
            User user = User.builder()
                    .login(login)
                    .password(password)
                    .accessLevel(accessLevel)
                    .build();
            userRepository.save(user);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public User getUser(Long id) {
        return userRepository.getUserByUserId(id);
    }

    public void addUser(User user) {
        try {
            userRepository.save(user);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<User> getAllUsers() {
        List<User> users =
                userRepository.findAll();
        return users;
    }

    public void updateUserAccessMode(@NotNull User user,
                                     String accessMode) {
        try {
            user.setAccessLevel(accessMode);
            userRepository.save(user);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void updateUserPassword(@NotNull User user,
                                   String password) {
        try {
            user.setPassword(password);
            userRepository.save(user);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<User> getUsers() {
        List<User> users;
        try {
            users = userRepository.findAll();
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return users;
    }

    public void deleteUser(User user) {
        try {
            userRepository.delete(user);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void deleteUser(Long id) {
        try {
            userRepository.deleteById(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }
}
