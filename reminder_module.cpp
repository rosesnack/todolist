#include "reminder_module.h"
#include <ctime>
#include <iostream>

// Reminder �๹�캯��ʵ��
Reminder::Reminder(int id, std::string name, std::tm rt, std::tm dt)
    : taskID(id), taskname(name), remindTime(rt), dueTime(dt) {
}

// ��������֪ͨ
void Reminder::sendNotification() const {
    std::cout << "������������������������������������" << std::endl;
    std::cout << "Reminder [ID: " << taskID << "]: task \"" << taskname << "\" will due at ";
    std::cout << std::asctime(&dueTime);  // �������ʱ��
    std::cout << "������������������������������������" << std::endl;
}

// ����С����������������ȶ������򣨰�ʱ���Ⱥ�˳��
bool Reminder::operator<(const Reminder& other) const {
    return std::mktime(const_cast<std::tm*>(&remindTime)) > std::mktime(const_cast<std::tm*>(&other.remindTime));
}

ReminderManager::ReminderManager() {}

void ReminderManager::addReminder(int id, std::string name, std::tm rt, std::tm dt) {
    reminders.push(Reminder(id, name, rt, dt));
}

void ReminderManager::send_notifications() {
    if (!reminders.empty()) {
        Reminder next_reminder = reminders.top(); // ��ȡ���������
        std::time_t now = std::time(nullptr);

        if (now >= std::mktime(&next_reminder.remindTime)) {
            // �����ǰʱ���Ѿ���������ʱ�䣬����֪ͨ
            next_reminder.sendNotification();
            reminders.pop(); // ɾ���Ѵ��������
        }
    }
}

void ReminderManager::removeReminder(int taskID) {
    // ����һ���µĶ��У������洢δ��ɾ��������
    std::priority_queue<Reminder> newQueue;

    // ����ԭʼ���У�������Ҫɾ�������Ѹ��Ƶ��¶�����
    while (!reminders.empty()) {
        Reminder reminder = reminders.top();
        reminders.pop();

        if (reminder.taskID != taskID) {
            newQueue.push(reminder); // �������ID��ƥ�䣬�ͱ���������
        }
    }

    // �滻�ɶ���Ϊ�µĶ���
    reminders = newQueue;
}
