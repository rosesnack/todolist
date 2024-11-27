#ifndef REMINDER_MODULE_H
#define REMINDER_MODULE_H

#include <ctime>
#include <iostream>

// ������
class Reminder {
public:
    int reminderID;        // ����ID
    std::tm remindTime;    // ����ʱ��

    Reminder() : reminderID(0), remindTime({ 0 }) {}

    void setReminder(int taskID, const std::tm& remindTime) {
        this->reminderID = taskID;
        this->remindTime = remindTime;
    }

    void sendNotification() {
        //todo����ʵ��Ӧ���и���ϵͳʱ�䷢��֪ͨ
        
        // ��������ͨ�������Ϣ��ʵ��
        std::cout << "Reminder: Task ID " << reminderID << " is due at ";
        std::cout << std::asctime(&remindTime);  // �������ʱ��
    }
};

#endif // REMINDER_MODULE_H
