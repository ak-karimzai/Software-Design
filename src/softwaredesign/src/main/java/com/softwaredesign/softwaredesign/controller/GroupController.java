package com.softwaredesign.softwaredesign.controller;

import com.softwaredesign.softwaredesign.entity.Group;
import com.softwaredesign.softwaredesign.repository.GroupRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
@AllArgsConstructor
public class GroupController {
    private GroupRepository groupRepository;

    public void addGroup(String name,
                         Integer numberOfStudents) {
        Group group = Group.builder()
                .name(name)
                .numberOfStudents(numberOfStudents)
                .build();
        groupRepository.save(group);
    }

    public void addGroup(Group group) {
        groupRepository.save(group);
    }

    public Group getGroup(Long id) {
        return groupRepository.getGroupsByGroupId(id);
    }

    public void deleteGroup(Group group) {
        groupRepository.delete(group);
    }

    public void deleteGroup(Long id) {
        groupRepository.deleteById(id);
    }

    public void updateGroupStudentNumbers(Group group,
                                         Integer numberOfStudents) {
        group.setNumberOfStudents(numberOfStudents);
        groupRepository.save(group);
    }

    public List<Group> getAllGroups() {
        return groupRepository.findAll();
    }

    public void updateGroupName(Group group,
                                String name) {
        group.setName(name);
        groupRepository.save(group);
    }
}
