#ifndef USER_MODULE_H
#define USER_MODULE_H

#include <string>
#include <vector>
#include <ctime>  // ����std::tm
#include "task_module.h"
#include "sync_module.h"
#include "archive_module.h"
tm inputDate();

class User {
public:
    int userID;
    std::string username;
    std::vector<Task> tasks;
    std::unique_ptr<Archive> archive;
    std::unique_ptr<SyncService> syncService;

    User(int id, const std::string& name);

    // �������
    void addTask(Task task);

    // �������Ϊ���
    void completeTask(int taskID);

    // �༭�����ڱ���ʵ���в����ã�����ɹ������޸�ʵ�֣�
    void editTask(int taskID, const Task& updatedTask);

    // ɾ������
    void deleteTask(int taskID);

    // �鿴���������Ϣ
    void viewTaskDetail(int taskID);

    // �ӳ�����Ľ�ֹ����
    void extendDeadline(int taskID);

    // ͬ�����ݵ��ƶ�
    void syncToCloud();

    // ���ƶ�ͬ������
    void syncFromCloud();
};

#endif // USER_MODULE_H
