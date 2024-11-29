#ifndef USER_MODULE_H
#define USER_MODULE_H

#include <queue>
#include <string>
#include <vector>
#include <ctime>  // ����std::tm
#include "task_module.h"
#include "sync_module.h"
#include "archive_module.h"
#include "tools.h"
tm inputDate();

class User {
public:
    int userID;
    std::string username;
    std::vector<Task> tasks;
    std::unique_ptr<Archive> archive;
    std::unique_ptr<SyncService> syncService;
    std::unique_ptr<ReminderManager> reminderManager;

    User(int id, const std::string& name);

    void addTask(Task task);  // �������
    void completeTask(int taskID);  // �������Ϊ���
    void editTask(int taskID, const Task& updatedTask);  // �༭�����ڱ���ʵ���в����ã�����ɹ������޸�ʵ�֣�
    void deleteTask(int taskID);  // ɾ������
    void viewTaskDetail(int taskID);  // �鿴���������Ϣ
    void extendDeadline(int taskID);  // �ӳ�����Ľ�ֹ����
    void syncToCloud();  // ͬ�����ݵ��ƶ�
    void syncFromCloud();  // ���ƶ�ͬ������
    void printAllTasks();   // ��ӡ��������
    void printTasksByPriority(Priority priority);  // ��ӡָ�����ȼ�������
};

#endif // USER_MODULE_H