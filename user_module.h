#ifndef USER_MODULE_H
#define USER_MODULE_H

#include <string>
#include <vector>
#include <ctime>  // 包含std::tm
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

    // 添加任务
    void addTask(Task task);

    // 标记任务为完成
    void completeTask(int taskID);

    // 编辑任务（在本次实验中不调用，具体可供后续修改实现）
    void editTask(int taskID, const Task& updatedTask);

    // 删除任务
    void deleteTask(int taskID);

    // 查看任务具体信息
    void viewTaskDetail(int taskID);

    // 延长任务的截止日期
    void extendDeadline(int taskID);

    // 同步数据到云端
    void syncToCloud();

    // 从云端同步数据
    void syncFromCloud();
};

#endif // USER_MODULE_H
