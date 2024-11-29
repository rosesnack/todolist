#ifndef USER_MODULE_H
#define USER_MODULE_H

#include <queue>
#include <string>
#include <vector>
#include <ctime>  // 包含std::tm
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

    void addTask(Task task);  // 添加任务
    void completeTask(int taskID);  // 标记任务为完成
    void editTask(int taskID, const Task& updatedTask);  // 编辑任务（在本次实验中不调用，具体可供后续修改实现）
    void deleteTask(int taskID);  // 删除任务
    void viewTaskDetail(int taskID);  // 查看任务具体信息
    void extendDeadline(int taskID);  // 延长任务的截止日期
    void syncToCloud();  // 同步数据到云端
    void syncFromCloud();  // 从云端同步数据
    void printAllTasks();   // 打印所有任务
    void printTasksByPriority(Priority priority);  // 打印指定优先级的任务
};

#endif // USER_MODULE_H