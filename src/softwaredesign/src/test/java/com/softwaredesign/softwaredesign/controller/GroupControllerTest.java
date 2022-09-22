package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.repository.GroupRepository;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
//@DataJpaTest
class GroupControllerTest {
    @Autowired
    private GroupRepository groupRepository;
    private GroupController groupController;

    @Test
    public void testAddGroup() {
        Group group = Group.builder()
                .name("A12")
                .numberOfStudents(30)
                .build();
        groupController.addGroup(group);
        var groups = groupController.getAllGroups();
        var group01 = groups.get(groups.size() - 1);

        Assertions.assertEquals(group.getName(), group01.getName());
        Assertions.assertEquals(group.getNumberOfStudents(), group01.getNumberOfStudents());

        groupRepository.delete(group01);
    }

    @Test
    public void testUpdateGroup() {
        Group group = Group.builder()
                .name("A12")
                .numberOfStudents(30)
                .build();
        groupRepository.save(group);

        var groups = groupRepository.findAll();
        int numberOfGroups = groups.size();

        var group01 = groups.get(groups.size() - 1);
        groupRepository.delete(group01);

        groups = groupRepository.findAll();
        int numberOfGroupsAfterDeletion = groups.size();

        Assertions.assertNotEquals(numberOfGroups, numberOfGroupsAfterDeletion);
    }

    @Test
    public void testUpdateGroupName() {
        Group group = Group.builder()
                .name("A12")
                .numberOfStudents(30)
                .build();
        groupController.addGroup(group);
        var groups = groupController.getAllGroups();
        var group01 = groups.get(groups.size() - 1);

        String name = "New Name";

        group01.setName(name);
        groupController.addGroup(group01);

        group01 = groups.get(groups.size() - 1);

        Assertions.assertEquals(group01.getName(), name);
        groupController.deleteGroup(group01);
    }
}