#include "archive_module.h"
#include <iostream>

// 构造函数，初始化归档ID
Archive::Archive(int id) : archiveID(id) {}

// 归档已完成任务
void Archive::archiveCompletedTask(const Task& task) {
    if (task.isCompleted) {  // 只有完成的任务才能归档
        completedTasks.push_back(task);
        std::cout << "Task \"" << task.name << "\" has been archived." << std::endl;
    }
    else {
        std::cout << "Task \"" << task.name << "\" is not completed yet and cannot be archived." << std::endl;
    }
}

// 查看归档任务
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