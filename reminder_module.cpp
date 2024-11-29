#include "reminder_module.h"
#include <ctime>
#include <iostream>

// Reminder 类构造函数实现
Reminder::Reminder(int id, std::string name, std::tm rt, std::tm dt)
    : taskID(id), taskname(name), remindTime(rt), dueTime(dt) {
}

// 发送提醒通知
void Reminder::sendNotification() const {
    std::cout << "——————————————————" << std::endl;
    std::cout << "Reminder [ID: " << taskID << "]: task \"" << taskname << "\" will due at ";
    std::cout << std::asctime(&dueTime);  // 输出提醒时间
    std::cout << "——————————————————" << std::endl;
}

// 重载小于运算符，用于优先队列排序（按时间先后顺序）
bool Reminder::operator<(const Reminder& other) const {
    return std::mktime(const_cast<std::tm*>(&remindTime)) > std::mktime(const_cast<std::tm*>(&other.remindTime));
}

ReminderManager::ReminderManager() {}

void ReminderManager::addReminder(int id, std::string name, std::tm rt, std::tm dt) {
    reminders.push(Reminder(id, name, rt, dt));
}

void ReminderManager::send_notifications() {
    if (!reminders.empty()) {
        Reminder next_reminder = reminders.top(); // 获取最早的提醒
        std::time_t now = std::time(nullptr);

        if (now >= std::mktime(&next_reminder.remindTime)) {
            // 如果当前时间已经到达提醒时间，发送通知
            next_reminder.sendNotification();
            reminders.pop(); // 删除已处理的提醒
        }
    }
}

void ReminderManager::removeReminder(int taskID) {
    // 创建一个新的队列，用来存储未被删除的提醒
    std::priority_queue<Reminder> newQueue;

    // 遍历原始队列，将不需要删除的提醒复制到新队列中
    while (!reminders.empty()) {
        Reminder reminder = reminders.top();
        reminders.pop();

        if (reminder.taskID != taskID) {
            newQueue.push(reminder); // 如果任务ID不匹配，就保留该提醒
        }
    }

    // 替换旧队列为新的队列
    reminders = newQueue;
}
