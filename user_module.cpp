#include "user_module.h"
#include "task_module.h"
#include <iostream>
#include <algorithm>

// �û��๹�캯��
User::User(int id, const std::string& name) : userID(id), username(name), 
archive(std::make_unique<Archive>(id)), syncService(std::make_unique<SyncService>(id)),
reminderManager(std::make_unique<ReminderManager>()){}

// �������
void User::addTask(Task task) {
    tasks.push_back(task);
    reminderManager->addReminder(task.taskID, task.name, task.remindTime, task.dueTime);
    std::cout << "Task added: " << task.name << std::endl;
}

// �������
void User::completeTask(int taskID) {
    // ��������
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

// �༭�����ڱ���ʵ���в����ã�����ɹ������޸�ʵ�֣�
void User::editTask(int taskID, const Task& updatedTask) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        *it = updatedTask;
        std::cout << "Task edited: " << updatedTask.name << std::endl;
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
    //todo���޸�������ض�����
}

// ɾ������
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

// �鿴���������Ϣ
void User::viewTaskDetail(int taskID) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        it->printTaskDetail();
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
}

// �ӳ�����Ľ�ֹ����
void User::extendDeadline(int taskID) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [taskID](const Task& t) { return t.taskID == taskID; });
    if (it != tasks.end()) {
        std::cin.ignore();
        it->dueTime = inputDate(); // ���������ֹ����
        std::cout << "Deadline extended for task: " << it->name << std::endl;
    }
    else {
        std::cout << "Task with ID " << taskID << " not found." << std::endl;
    }
}

// ͬ�����ݵ��ƶ�
void User::syncToCloud() {
    syncService->syncToCloud();
}

// ���ƶ�ͬ������
void User::syncFromCloud() {
    syncService->syncFromCloud();
}

// ��ӡ��������
void User::printAllTasks() {
    std::cout << "Task todo list:";
    if (tasks.empty()) {
        std::cout << "None" << std::endl;
        return;
    }

    // �� dueTime ����ʹ�� lambda ���ʽ���Ƚ������ dueTime
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        // �Ƚ� dueTime ����ݡ��·ݡ����ڵ��ֶ�
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

// ��ӡָ�����ȼ�������
void User::printTasksByPriority(Priority priority) {
    std::cout << "Tasks with priority ";
    switch (priority) {
    case LOW:    std::cout << "LOW"; break;
    case MEDIUM: std::cout << "MEDIUM"; break;
    case HIGH:   std::cout << "HIGH"; break;
    default:     std::cout << "UNKNOWN"; break;
    }
    std::cout << ":" << std::endl;

    // ɸѡ������ָ�����ȼ�������
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
