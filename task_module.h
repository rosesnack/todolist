#ifndef TASK_MODULE_H
#define TASK_MODULE_H

#include <string>
#include <ctime>
#include "reminder_module.h"

// 任务优先级枚举
enum Priority {
    LOW,
    MEDIUM,
    HIGH
};

enum Color {
    RED, BLUE, GREEN, YELLOW, PURPLE
};

// 任务类别
class TaskCategory {
public:
    Color color;
    std::string customName;  // 自定义分类名称

    // 默认构造函数
    TaskCategory(Color col) : color(col), customName("Default"){}  // 默认分类为 "Default"

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


// 任务类
class Task {
public:
    int taskID;               // 任务ID
    std::string name;         // 任务名称
    std::string description;  // 任务描述
    std::tm dueTime;          // 任务截止时间
    std::tm remindTime;       // 提醒时间
    Priority priority;        // 任务优先级
    TaskCategory category;    // 任务分类
    bool isCompleted;         // 任务是否完成
    Reminder reminder;        // 提醒类对象

    Task(int id, const std::string& taskName, const std::string& taskDesc, 
        const std::tm& due, const std::tm& remind, Priority p, Color c);

    void setReminder(const std::tm& remindTime);
    void markCompleted();
    void setReminderTime(const std::tm& time); // 用于设置任务提醒时间
    void sendReminder(); // 用于发送任务提醒
    void printTask() const;  //用于打印任务的简略信息
    void printTaskDetail() const;  //用于打印任务的详细信息
};

#endif // TASK_MODULE_H
