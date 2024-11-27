#include "user_module.h"
#include "task_module.h"
#include <iostream>
#include <algorithm>

// 用户类构造函数
User::User(int id, const std::string& name) : userID(id), username(name), archive(std::make_unique<Archive>(id)), syncService(std::make_unique<SyncService>(id)) {}

// 添加任务
void User::addTask(Task task) {
    tasks.push_back(task);
    std::cout << "Task added: " << task.name << std::endl;
}

// 完成任务
void User::completeTask(int taskID) {
    // 查找任务
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        it->markCompleted();
        archive->archiveCompletedTask(*it);
        tasks.erase(it);
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
}

// 编辑任务（在本次实验中不调用，具体可供后续修改实现）
void User::editTask(int taskID, const Task& updatedTask) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        *it = updatedTask;
        std::cout << "Task edited: " << updatedTask.name << std::endl;
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
    //todo：修改任务的特定部分
}

// 删除任务
void User::deleteTask(int taskID) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task deleted: " << taskID << std::endl;
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
}

// 查看任务具体信息
void User::viewTaskDetail(int taskID) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        it->printTaskDetail();
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
}

// 延长任务的截止日期
void User::extendDeadline(int taskID) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        std::cin.ignore();
        it->dueTime = inputDate(); // 更新任务截止日期
        std::cout << "Deadline extended for task: " << it->name << std::endl;
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
}

// 同步数据到云端
void User::syncToCloud() {
    syncService->syncToCloud();
}

// 从云端同步数据
void User::syncFromCloud() {
    syncService->syncFromCloud();
}
