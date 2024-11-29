#ifndef REMINDER_MODULE_H
#define REMINDER_MODULE_H

#include <ctime>
#include <iostream>
#include <queue>
#include <string>

// ������
class Reminder {
public:
    int taskID;            // ����ID
    std::tm remindTime;    // ����ʱ��
    std::tm dueTime;    // ddl
    std::string taskname;  // ��������

    // ���캯��
    Reminder(int id, std::string name, std::tm rt, std::tm dt);

    // ��������֪ͨ
    void sendNotification() const;

    // ����С����������������ȶ������򣨰�ʱ���Ⱥ�˳��
    bool operator<(const Reminder& other) const;
};

class ReminderManager {
public:
    // ���ȶ��У�������ʱ������
    std::priority_queue<Reminder> reminders;

    ReminderManager();

    // ���reminder
    void addReminder(int id, std::string name, std::tm rt, std::tm dt);

    // ����Ƿ���reminder���ڲ�����֪ͨ
    void send_notifications();

    // ��������IDɾ��ָ������
    void removeReminder(int taskID);
};

#endif // REMINDER_MODULE_H
