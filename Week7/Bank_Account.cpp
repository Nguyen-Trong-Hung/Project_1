#include <bits/stdc++.h>

using namespace std;

int number_transactions;
int allofmoney = 0;
map <string,pair<int,int>> account;

int main(){
    string to_account;
    int money;
    string time_point;
    string atm;
    string cmd1,cmd2;
    while(cin >> cmd1){
        if(cmd1 == "#")
            break;
        string from_account = cmd1;
        number_transactions++;
        cin >> to_account >> money >> time_point >> atm;
        allofmoney += money;
        if(account.find(from_account) != account.end()){
            account[from_account].first += money;
            account[from_account].second += 1;
        }
        else    
        {
            account.insert({from_account,{money, 1}});
        }

        if(account.find(to_account) == account.end()){
            account.insert({to_account,{0, 0}});
        }
    }

    while(cin >> cmd2){
        if(cmd2 == "#")
            break;
        else if(cmd2 == "?number_transactions"){
            cout << number_transactions << "\n";
        }
        else if(cmd2 == "?total_money_transaction"){
            cout << allofmoney << "\n";
        }
        else if(cmd2 == "?list_sorted_accounts"){
            for(pair<string,pair<int, int>> x : account){
                cout << x.first << " ";
            }
            cout << "\n";
        }
        else if(cmd2 == "?total_money_transaction_from")
        {
            string Acc;
            cin >> Acc;
            cout << account[Acc].first << "\n";
        }
        else if(cmd2 == "?inspect_cycle")
        {
            string Acc;
            int k;
            cin >> Acc >> k;
            if(k == account[Acc].second)
                cout << 1 << "\n";
            else    
                cout << 0 << "\n";
        }
    }
}