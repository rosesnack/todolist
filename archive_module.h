#ifndef ARCHIVE_MODULE_H
#define ARCHIVE_MODULE_H

#include <vector>
#include "task_module.h"

class Archive {
public:
    int archiveID;                    // 归档ID，可认为与userID相等
    std::vector<Task> completedTasks; // 完成的任务列表

    Archive(int id);

    // 查看归档任务
    void viewArchivedTasks() const;

    // 归档已完成任务
    void archiveCompletedTask(const Task& task);
};

#endif // ARCHIVE_MODULE_H
