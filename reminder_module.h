#ifndef REMINDER_MODULE_H
#define REMINDER_MODULE_H

#include <ctime>
#include <iostream>
#include <queue>
#include <string>

// 提醒类
class Reminder {
public:
    int taskID;            // 任务ID
    std::tm remindTime;    // 提醒时间
    std::tm dueTime;    // ddl
    std::string taskname;  // 任务名称

    // 构造函数
    Reminder(int id, std::string name, std::tm rt, std::tm dt);

    // 发送提醒通知
    void sendNotification() const;

    // 重载小于运算符，用于优先队列排序（按时间先后顺序）
    bool operator<(const Reminder& other) const;
};

class ReminderManager {
public:
    // 优先队列，按提醒时间排序
    std::priority_queue<Reminder> reminders;

    ReminderManager();

    // 添加reminder
    void addReminder(int id, std::string name, std::tm rt, std::tm dt);

    // 检查是否有reminder到期并发送通知
    void send_notifications();

    // 根据任务ID删除指定提醒
    void removeReminder(int taskID);
};

#endif // REMINDER_MODULE_H
