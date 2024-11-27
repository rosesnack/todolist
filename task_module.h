#ifndef TASK_MODULE_H
#define TASK_MODULE_H

#include <string>
#include <ctime>
#include "reminder_module.h"

// �������ȼ�ö��
enum Priority {
    LOW,
    MEDIUM,
    HIGH
};

enum Color {
    RED, BLUE, GREEN, YELLOW, PURPLE
};

// �������
class TaskCategory {
public:
    Color color;
    std::string customName;  // �Զ����������

    // Ĭ�Ϲ��캯��
    TaskCategory(Color col) : color(col), customName("Default"){}  // Ĭ�Ϸ���Ϊ "Default"

    void setCustomName(const std::string& newName) {
        customName = newName;
    }

    std::string getCustomName() const {
        return customName;
    }

    Color getColor() const {
        return color;
    }
};


// ������
class Task {
public:
    int taskID;               // ����ID
    std::string name;         // ��������
    std::string description;  // ��������
    std::tm dueTime;          // �����ֹʱ��
    std::tm remindTime;       // ����ʱ��
    Priority priority;        // �������ȼ�
    TaskCategory category;    // �������
    bool isCompleted;         // �����Ƿ����
    Reminder reminder;        // ���������

    Task(int id, const std::string& taskName, const std::string& taskDesc, 
        const std::tm& due, const std::tm& remind, Priority p, Color c);

    void setReminder(const std::tm& remindTime);
    void markCompleted();
    void setReminderTime(const std::tm& time); // ����������������ʱ��
    void sendReminder(); // ���ڷ�����������
    void printTask() const;  //���ڴ�ӡ����ļ�����Ϣ
    void printTaskDetail() const;  //���ڴ�ӡ�������ϸ��Ϣ
};

#endif // TASK_MODULE_H
