#include<bits/stdc++.h>
#include<set>

using namespace std;

int main(){
    string cmd1,cmd2;
    set<string> s;
    while(cin >> cmd1){
        s.insert(cmd1);
        if(cmd1 == "*")
            break;
    }
    while(cin >> cmd2){
        if(cmd2 == "insert"){
            string k;
            cin >> k;
            if(s.count(k))  cout << 0 << "\n";
            else {
                cout << 1 << "\n";
                s.insert(k);
            }
        }
        else if(cmd2 == "find"){
            string k;
            cin >> k;
            if(s.count(k))  cout << 1 << "\n";
            else    cout << 0 <<"\n";
            }
            else if(cmd2 == "***")
                    break;
    }
    cout << s.size();
}