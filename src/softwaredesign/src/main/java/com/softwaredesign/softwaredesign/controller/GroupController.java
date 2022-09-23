package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.exception.DatabaseAccessException;
import com.softwaredesign.softwaredesign.repository.GroupRepository;
import lombok.AllArgsConstructor;
import org.jetbrains.annotations.NotNull;
import org.springframework.dao.DataAccessException;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class GroupController {
    private GroupRepository groupRepository;

    public void addGroup(String name,
                         Integer numberOfStudents) {
        try {
            Group group = Group.builder()
                    .name(name)
                    .numberOfStudents(numberOfStudents)
                    .build();
            groupRepository.save(group);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }

    }

    public void addGroup(Group group) {
        try {
            groupRepository.save(group);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public Group getGroup(Long id) {
        Group returnedGroup;
        try {
            returnedGroup = groupRepository.getGroupsByGroupId(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
        return returnedGroup;
    }

    public void deleteGroup(Group group) {
        try {
            groupRepository.delete(group);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void deleteGroup(Long id) {
        try {
            groupRepository.deleteById(id);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public void updateGroupStudentNumbers(Group group,
                                         Integer numberOfStudents) {
        try {
            group.setNumberOfStudents(numberOfStudents);
            groupRepository.save(group);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }

    public List<Group> getAllGroups() {
        List<Group> groups;
        try {
            groups =  groupRepository.findAll();
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }

        return groups;
    }

    public void updateGroupName(@NotNull Group group,
                                String name) {
        try {
            group.setName(name);
            groupRepository.save(group);
        } catch (DataAccessException e) {
            throw new DatabaseAccessException(e.getMessage());
        }
    }
}
