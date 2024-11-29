#include "user_module.h"
#include "task_module.h"
#include <iostream>
#include <algorithm>

// 用户类构造函数
User::User(int id, const std::string& name) : userID(id), username(name), 
archive(std::make_unique<Archive>(id)), syncService(std::make_unique<SyncService>(id)),
reminderManager(std::make_unique<ReminderManager>()){}

// 添加任务
void User::addTask(Task task) {
    tasks.push_back(task);
    reminderManager->addReminder(task.taskID, task.name, task.remindTime, task.dueTime);
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
        reminderManager->removeReminder(taskID);
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
        reminderManager->removeReminder(taskID);
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

// 打印所有任务
void User::printAllTasks() {
    std::cout << "Task todo list:";
    if (tasks.empty()) {
        std::cout << "None" << std::endl;
        return;
    }

    // 按 dueTime 排序，使用 lambda 表达式来比较任务的 dueTime
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        // 比较 dueTime 的年份、月份、日期等字段
        if (a.dueTime.tm_year != b.dueTime.tm_year)
            return a.dueTime.tm_year < b.dueTime.tm_year;
        if (a.dueTime.tm_mon != b.dueTime.tm_mon)
            return a.dueTime.tm_mon < b.dueTime.tm_mon;
        if (a.dueTime.tm_mday != b.dueTime.tm_mday)
            return a.dueTime.tm_mday < b.dueTime.tm_mday;
        if (a.dueTime.tm_hour != b.dueTime.tm_hour)
            return a.dueTime.tm_hour < b.dueTime.tm_hour;
        return a.dueTime.tm_min < b.dueTime.tm_min;
        });

    std::cout << std::endl;
    for (const Task& task : tasks) {
        task.printTask();
    }
}

// 打印指定优先级的任务
void User::printTasksByPriority(Priority priority) {
    std::cout << "Tasks with priority ";
    switch (priority) {
    case LOW:    std::cout << "LOW"; break;
    case MEDIUM: std::cout << "MEDIUM"; break;
    case HIGH:   std::cout << "HIGH"; break;
    default:     std::cout << "UNKNOWN"; break;
    }
    std::cout << ":" << std::endl;

    // 筛选出符合指定优先级的任务
    std::vector<Task> filteredTasks;
    for (const Task& task : tasks) {
        if (task.priority == priority) {
            filteredTasks.push_back(task);
        }
    }

    if (filteredTasks.empty()) {
        std::cout << "No tasks with this priority." << std::endl;
    }
    else {
        for (const Task& task : filteredTasks) {
            task.printTask();
        }
    }
}
