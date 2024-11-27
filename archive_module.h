#ifndef ARCHIVE_MODULE_H
#define ARCHIVE_MODULE_H

#include <vector>
#include "task_module.h"

class Archive {
public:
    int archiveID;                    // �鵵ID������Ϊ��userID���
    std::vector<Task> completedTasks; // ��ɵ������б�

    Archive(int id);

    // �鿴�鵵����
    void viewArchivedTasks() const;

    // �鵵���������
    void archiveCompletedTask(const Task& task);
};

#endif // ARCHIVE_MODULE_H
