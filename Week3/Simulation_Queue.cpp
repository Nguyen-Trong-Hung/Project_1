#include <bits/stdc++.h>
#include<queue>

using namespace std;

int main(){
    string command;
    queue <int> box;
    while(cin >> command){
        if(command == "PUSH"){
            int value;
            cin >> value;
            box.push(value);
        }
        else if(command == "POP"){
            if(box.empty()){
                cout << "NULL" << endl;
            }
            else{
                cout << box.front() << endl;
                box.pop();
            }
        }
            else if(command == "#")
                    break;
    }
}