package com.softwaredesign.softwaredesign.controller;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class UserControllerTest {
    @Autowired
    private UserController userController;

    @Test
    public void testAddUser() {
        String name = "mmm";
        String password = "ppp";
        String accessLevel = "Admin";
        userController.addUser(name, password, accessLevel);

        var users = userController.getAllUsers();
        var lastUser = users.get(users.size() - 1);

        Assertions.assertEquals(lastUser.getLogin(), name);
        Assertions.assertEquals(lastUser.getPassword(), password);
        Assertions.assertEquals(lastUser.getAccessLevel(), accessLevel);

        userController.deleteUser(lastUser);
    }

    @Test
    public void testDeleteUser() {
        String name = "mmm";
        String password = "ppp";
        String accessLevel = "Admin";
        userController.addUser(name, password, accessLevel);

        var users = userController.getAllUsers();
        var lastUser = users.get(users.size() - 1);

        userController.deleteUser(lastUser);

        users = userController.getAllUsers();
        lastUser = users.get(users.size() - 1);

        Assertions.assertNotEquals(lastUser.getLogin(), name);
        Assertions.assertNotEquals(lastUser.getPassword(), password);
        Assertions.assertNotEquals(lastUser.getAccessLevel(), accessLevel);

    }
}