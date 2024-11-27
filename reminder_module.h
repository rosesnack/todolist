#ifndef REMINDER_MODULE_H
#define REMINDER_MODULE_H

#include <ctime>
#include <iostream>

// 提醒类
class Reminder {
public:
    int reminderID;        // 提醒ID
    std::tm remindTime;    // 提醒时间

    Reminder() : reminderID(0), remindTime({ 0 }) {}

    void setReminder(int taskID, const std::tm& remindTime) {
        this->reminderID = taskID;
        this->remindTime = remindTime;
    }

    void sendNotification() {
        //todo：在实际应用中根据系统时间发送通知
        
        // 假设提醒通过输出信息来实现
        std::cout << "Reminder: Task ID " << reminderID << " is due at ";
        std::cout << std::asctime(&remindTime);  // 输出提醒时间
    }
};

#endif // REMINDER_MODULE_H
