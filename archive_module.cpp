#include "archive_module.h"
#include <iostream>

// ���캯������ʼ���鵵ID
Archive::Archive(int id) : archiveID(id) {}

// �鵵���������
void Archive::archiveCompletedTask(const Task& task) {
    if (task.isCompleted) {  // ֻ����ɵ�������ܹ鵵
        completedTasks.push_back(task);
        std::cout << "Task \"" << task.name << "\" has been archived." << std::endl;
    }
    else {
        std::cout << "Task \"" << task.name << "\" is not completed yet and cannot be archived." << std::endl;
    }
}

// �鿴�鵵����
void Archive::viewArchivedTasks() const {
    if (completedTasks.empty()) {
        std::cout << "No completed tasks in archive." << std::endl;
        return;
    }

    std::cout << "Archived Completed Tasks:" << std::endl;
    std::string prio = "LOW";
    for (const Task& task : completedTasks) {
        task.printTask();
    }
}