#include "tools.h"
#include <iostream>
#include <string>

using namespace std;

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
