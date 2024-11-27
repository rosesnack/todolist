#include "user_module.h"
#include "task_module.h"
#include <iostream>
#include <algorithm>

// �û��๹�캯��
User::User(int id, const std::string& name) : userID(id), username(name), archive(std::make_unique<Archive>(id)), syncService(std::make_unique<SyncService>(id)) {}

// �������
void User::addTask(Task task) {
    tasks.push_back(task);
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
