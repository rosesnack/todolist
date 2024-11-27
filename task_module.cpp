#include "task_module.h"
#include <iostream>

// 任务类构造函数
Task::Task(int id, const std::string& taskName, const std::string& taskDesc, const std::tm& due, 
    const std::tm& remind, Priority p, Color c)
    : taskID(id), name(taskName), description(taskDesc), dueTime(due), remindTime(remind), 
    priority(p), isCompleted(false), category(c) {
    reminder.setReminder(taskID, remindTime);  // 初始化提醒
}

// 设置提醒时间
void Task::setReminder(const std::tm& remindTime) {
    this->remindTime = remindTime;
    reminder.setReminder(taskID, remindTime); // 使用 Reminder 类设置提醒
}

// 完成任务
void Task::markCompleted() {
    isCompleted = true;
    std::cout << "Task completed: " << name << std::endl;
}

// 设置任务提醒时间
void Task::setReminderTime(const std::tm& time) {
    remindTime = time;
    reminder.setReminder(taskID, remindTime); // 通过 Reminder 类来设置提醒
}

// 发送任务提醒
void Task::sendReminder() {
    if (!isCompleted) {
        reminder.sendNotification(); // 调用 Reminder 类的发送通知方法
    }
}

// 打印任务的简略信息
void Task::printTask() const{
    std::string prio = "LOW";
    switch (priority) {
    case(0):
        prio = "LOW";
        break;
    case(1):
        prio = "MEDIUM";
        break;
    case(2):
        prio = "HIGH";
        break;
    default:
        std::cout << "Priority not correct, default to LOW" << std::endl;
    }
    std::cout << "Task ID: " << taskID
        << ", Name: " << name
        << ", Due Time: " << asctime(&dueTime)
        << ", Priority: " << prio
        << ", Color : " << category.color
        << "\n";
}

// 打印任务的详细信息
void Task::printTaskDetail() const {
    std::string prio = "LOW";
    switch (priority) {
    case(0):
        prio = "LOW";
        break;
    case(1):
        prio = "MEDIUM";
        break;
    case(2):
        prio = "HIGH";
        break;
    default:
        std::cout << "Priority not correct, default to LOW" << std::endl;
    }
    std::cout << "\nTask ID: " << taskID << std::endl
        << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Due Time: " << asctime(&dueTime)
        << "Remind Time: " << asctime(&remindTime)
        << "Priority: " << prio << std::endl
        << "Type: " << category.customName << std::endl
        << "Color : " << category.color << std::endl;
}