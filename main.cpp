#include <iostream>
#include <string>
#include <ctime>
#include "user_module.h"
#include "task_module.h"
#include "archive_module.h"

using namespace std;

// 帮助函数：获取当前时间
tm getCurrentTime() {
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    return tm;
}

// 帮助函数：输入日期
tm inputDate() {
    //cin.ignore();
    tm date = {};
    int year, month, day, hour, minute;
    string input;

    // 默认值
    const int defaultYear = 2024;
    const int defaultMonth = 12;
    const int defaultDay = 15;
    const int defaultHour = 18;
    const int defaultMinute = 30;

    // 输入年份
    cout << "Enter year (default " << defaultYear << "): ";
    getline(cin, input);
    if (input.empty()) {
        year = defaultYear;
    }
    else {
        year = stoi(input);
        while (year < 2024) {
            cout << "Enter the correct year (>=2024): ";
            getline(cin, input);
            if (input.empty()) {
                year = defaultYear;
                break;
            }
            year = stoi(input);
        }
    }

    // 输入月份
    cout << "Enter month (default " << defaultMonth << "): ";
    getline(cin, input);
    if (input.empty()) {
        month = defaultMonth;
    }
    else {
        month = stoi(input);
    }

    // 输入日期
    cout << "Enter day (default " << defaultDay << "): ";
    getline(cin, input);
    if (input.empty()) {
        day = defaultDay;
    }
    else {
        day = stoi(input);
    }

    // 输入小时
    cout << "Enter hour (default " << defaultHour << "): ";
    getline(cin, input);
    if (input.empty()) {
        hour = defaultHour;
    }
    else {
        hour = stoi(input);
    }

    // 输入分钟
    cout << "Enter minute (default " << defaultMinute << "): ";
    getline(cin, input);
    if (input.empty()) {
        minute = defaultMinute;
    }
    else {
        minute = stoi(input);
    }

    // 填充 tm 结构
    date.tm_year = year - 1900; // tm_year是从1900年开始
    date.tm_mon = month - 1;    // tm_mon是从0开始
    date.tm_mday = day;
    date.tm_hour = hour;
    date.tm_min = minute;
    date.tm_sec = 0;

    return date;
}


void printAllTasks(User* user) {
    cout << "Task todo list:";
    if (user->tasks.empty()) {
        cout << "None" << endl;
        return;
    }
    cout << endl;
    for (const Task& task : user->tasks) {
        task.printTask();
    }
}

int main() {
    int userID = 1;
    string username = "User1";
    User user(userID, username);  // 创建一个用户对象

    int taskID = 1;
    bool running = true;

    while (running) {
        system("cls");
        printAllTasks(&user);
        cout << "\n--- Task Management System ---\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Delete Task\n";
        cout << "4. View Task Detail\n";
        cout << "5. Extend Deadline\n";
        cout << "6. Edit Task\n";
        cout << "7. Sync To Cloud\n";
        cout << "8. Sync From Cloud\n";
        cout << "9. View Archived Tasks\n";
        cout << "10. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {  //1. Add Task
            system("cls");
            cout << "Add Task\n";

            // 输入任务名称，默认名称为 "task" + taskID
            cout << "Enter task name (default task" << taskID << "): ";
            string name;
            cin.ignore();  // 清除输入缓存
            getline(cin, name);
            if (name.empty()) {
                name = "task" + to_string(taskID);  // 如果用户没有输入，使用默认值
            }

            // 输入任务描述，默认描述为 "None"
            cout << "Enter task description (default None): ";
            string description;
            getline(cin, description);
            if (description.empty()) {
                description = "None";  // 如果用户没有输入，使用默认值
            }

            // 输入任务截止日期
            cout << "\nEnter task due time:\n";
            tm dueTime = inputDate();

            // 输入提醒时间
            cout << "\nEnter reminder time:\n";
            tm remindTime = inputDate();

            // 输入优先级，默认值为0（LOW）
            cout << "\nEnter priority: 0:LOW 1:MEDIUM 2:HIGH (default 0): ";
            string p;
            getline(cin, p);
            if (p.empty() || stoi(p) < 0 || stoi(p) > 2) { 
                p = "0";
            }

            // 输入颜色类型，默认值为0（RED）
            cout << "Enter color type: 0:RED, 1:BLUE, 2:GREEN, 3:YELLOW, 4:PURPLE (default 0): ";
            string c;
            getline(cin, c);
            if (c.empty() || stoi(c) < 0 || stoi(c) > 4) {
                c = "0";
            }

            cout << endl;

            // 创建任务并添加到用户的任务列表
            Task newTask(taskID++, name, description, dueTime, remindTime, (Priority)stoi(p), (Color)stoi(c));
            user.addTask(newTask);
            cout << "Task added successfully.\n";
            break;
        }

        case 2: {  // 2. Complete Task
            cout << "Enter task ID to mark as complete: ";
            int id;
            cin >> id;

            user.completeTask(id);
            break;
        }
        case 3: {  // 3. Delete Task
            cout << "Enter task ID to delete: ";
            int id;
            cin >> id;

            user.deleteTask(id);
            break;
        }
        case 4: {  // 4. View Task Detail
            cout << "Enter task ID to view detail: ";
            int id;
            cin >> id;

            user.viewTaskDetail(id);
            break;
        }
        case 5: {  // 5. Extend Deadline
            cout << "Enter task ID to extend ddl: ";
            int id;
            cin >> id;

            user.extendDeadline(id);
            break;
        }
        case 6: {  // 6. Edit Task
            cout << "此功能留待后续实现，现在可以删除任务后重新添加任务。\n";
            break;
        }
        case 7: {  // 7. Sync To Cloud
            user.syncToCloud();
            break;
        }
        case 8: {  // 8. Sync From Cloud
            user.syncFromCloud();
            break;
        }
        case 9: {  // 9. View Archived Tasks
            user.archive->viewArchivedTasks();
            break;
        }
        case 10: {  // 10. Exit
            cout << "Exiting Task Management System.\n";
            running = false;
            break;
        }
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
        system("pause");
    }
    return 0;
}
