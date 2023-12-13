#include <iostream>
#include <sstream>
#include <vector>

bool isValidDateFormat(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::string dayStr = date.substr(8, 2);
    std::string monthStr = date.substr(5, 2);
    std::string yearStr = date.substr(0, 4);

    // Xóa kí tự '0' ở đầu của ngày và tháng nếu có
    if (dayStr[0] == '0') {
        dayStr = dayStr.substr(1);
    }

    if (monthStr[0] == '0') {
        monthStr = monthStr.substr(1);
    }

    int day = std::stoi(dayStr);
    int month = std::stoi(monthStr);
    int year = std::stoi(yearStr);

    if (month < 1 || month > 12) {
        return false;
    }

    // Kiểm tra tính hợp lệ của ngày dựa trên giá trị tháng và năm
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int daysInMonth = 31;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {
        daysInMonth = isLeapYear ? 29 : 28;
    }

    if (day < 1 || day > daysInMonth) {
        return false;
    }

    return true;
}

std::vector<std::string> extractDateParts(const std::string& date) {
    std::vector<std::string> parts;
    std::istringstream iss(date);
    std::string part;

    while (getline(iss, part, '-')) {
        parts.push_back(part);
    }

    return parts;
}

int main() {
    std::string date;
    std::getline(std::cin, date);

    if (!isValidDateFormat(date)) {
        std::cout << "INCORRECT" << std::endl;
    } else {
        std::vector<std::string> parts = extractDateParts(date);

        // Xóa kí tự '0' ở đầu của ngày và tháng nếu có
        for (std::string& part : parts) {
            if (part.size() > 1 && part[0] == '0') {
                part = part.substr(1);
            }
        }

        for (const std::string& part : parts) {
            std::cout << part << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
