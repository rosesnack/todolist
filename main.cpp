#include <iostream>
#include <string>
#include <ctime>
#include "user_module.h"
#include "task_module.h"
#include "archive_module.h"
#include "tools.h"

using namespace std;


int main() {
    int userID = 1;
    string username = "User1";
    User user(userID, username);  // 创建一个用户对象

    int taskID = 1;
    bool running = true;

    while (running) {
        system("cls");
        user.printAllTasks();

        cout << "\n--- Task Management System ---\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Delete Task\n";
        cout << "4. View Task Detail\n";
        cout << "5. Extend Deadline\n";
        cout << "6. Filter Priority\n";
        cout << "7. Edit Task\n";
        cout << "8. Sync To Cloud\n";
        cout << "9. Sync From Cloud\n";
        cout << "10. View Archived Tasks\n";
        cout << "11. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {  // Add Task
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

        case 2: {  // Complete Task
            cout << "Enter task ID to mark as complete: ";
            int id;
            cin >> id;

            user.completeTask(id);
            break;
        }
        case 3: {  // Delete Task
            cout << "Enter task ID to delete: ";
            int id;
            cin >> id;

            user.deleteTask(id);
            break;
        }
        case 4: {  // View Task Detail
            cout << "Enter task ID to view detail: ";
            int id;
            cin >> id;

            user.viewTaskDetail(id);
            break;
        }
        case 5: {  // Extend Deadline
            cout << "Enter task ID to extend ddl: ";
            int id;
            cin >> id;

            user.extendDeadline(id);
            break;
        }
        case 6: {  // Filter Priority
            cout << "Enter priority: 0:LOW 1:MEDIUM 2:HIGH: ";
            int p;
            cin >> p;
            user.printTasksByPriority((Priority)p);
            break;
        }
        case 7: {  // Edit Task
            cout << "此功能留待后续实现，现在可以删除任务后重新添加任务。\n";
            break;
        }
        case 8: {  // Sync To Cloud
            user.syncToCloud();
            break;
        }
        case 9: {  // Sync From Cloud
            user.syncFromCloud();
            break;
        }
        case 10: {  // View Archived Tasks
            user.archive->viewArchivedTasks();
            break;
        }
        case 11: {  // Exit
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