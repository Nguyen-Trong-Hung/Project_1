#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
    stack<char> myStack;
    string command;
    getline(cin, command);
    for (int i = 0; i < command.size(); i++) {
        if (!myStack.empty() && myStack.top() == '(' && command[i] == ')')
            myStack.pop();
        else if (!myStack.empty() && myStack.top() == '{' && command[i] == '}')
                myStack.pop();
            else if (!myStack.empty() && myStack.top() == '[' && command[i] == ']')
                    myStack.pop();
                else 
                    myStack.push(command[i]);
            
    }

    if(myStack.empty())
        cout << "1";
    else
        cout << "0";

    return 0;
}