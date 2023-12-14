#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<int> stack;

    std::string command; // command (n): yêu cầu
    while (std::cin >> command) {
        if (command == "PUSH") {
            int value;
            std::cin >> value;
            stack.push(value);
        } else if (command == "POP") {
            if (stack.empty()) {
                std::cout << "NULL" << std::endl;
            } else {
                std::cout << stack.top() << std::endl;
                stack.pop();
            }
        }
    }

    return 0;
}