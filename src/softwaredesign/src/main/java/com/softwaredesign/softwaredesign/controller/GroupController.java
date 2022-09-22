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

    public Group getGroup(Long id) {
        return groupRepository.getGroupsByGroupId(id);
    }

    public void deleteGroup(Group group) {
        groupRepository.delete(group);
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
