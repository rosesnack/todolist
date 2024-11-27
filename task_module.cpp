#include "task_module.h"
#include <iostream>

// �����๹�캯��
Task::Task(int id, const std::string& taskName, const std::string& taskDesc, const std::tm& due, 
    const std::tm& remind, Priority p, Color c)
    : taskID(id), name(taskName), description(taskDesc), dueTime(due), remindTime(remind), 
    priority(p), isCompleted(false), category(c) {
    reminder.setReminder(taskID, remindTime);  // ��ʼ������
}

// ��������ʱ��
void Task::setReminder(const std::tm& remindTime) {
    this->remindTime = remindTime;
    reminder.setReminder(taskID, remindTime); // ʹ�� Reminder ����������
}

// �������
void Task::markCompleted() {
    isCompleted = true;
    std::cout << "Task completed: " << name << std::endl;
}

// ������������ʱ��
void Task::setReminderTime(const std::tm& time) {
    remindTime = time;
    reminder.setReminder(taskID, remindTime); // ͨ�� Reminder ������������
}

// ������������
void Task::sendReminder() {
    if (!isCompleted) {
        reminder.sendNotification(); // ���� Reminder ��ķ���֪ͨ����
    }
}

// ��ӡ����ļ�����Ϣ
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

// ��ӡ�������ϸ��Ϣ
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