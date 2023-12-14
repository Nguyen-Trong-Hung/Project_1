#include <bits/stdc++.h>

using namespace std;

int main(){
    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
    map <string,map<string,int>> revenueofshop;
    string cmd1;

    int numberorder = 0;
    int revenue = 0;
    while(true){
        cin >> cmd1;
        if(cmd1 == "#"){
            break;
        }
        customerID = cmd1;
        cin >> productID >> price >> shopID >> timePoint;
        numberorder++;
        revenue += price;

        if(revenueofshop.find(shopID) == revenueofshop.end()){
            revenueofshop.insert({shopID,{customerID,price}});
        }
        else if(revenueofshop[shopID].find(customerID) == revenueofshop[shopID].end()){
            revenueofshop[shopID].insert({customerID,price});
        }
        else{
            revenueofshop[shopID][customerID] += price;
        }
    }

    string cmd2;
    while(cin >> cmd2){
        if(cmd2 == "#"){
            break;
        }
        else if(cmd2 == "?total_number_orders"){
            cout << numberorder << "\n";
        }
        else if(cmd2 == "?total_revenue"){
            cout << revenue << "\n";
        }
        else if(cmd2 == "?revenue_of_shop"){
            string shop;
            cin >> shop;
            int money = 0;
            for(pair<string, pair<string,int>> v : revenueofshop){
                money += v.second.second;
            }
            cout << money << "\n";
        }
        else if(cmd2 == "?total_consume_of_customer_shop"){
            string product;
            string shop;
            cin >> product >> shop;
            cout << revenueofshop[shop][product] << "\n";
        }
        else if(cmd2 == "?total_revenue_in_period"){
            string fromtime;
            string totime;
            cin >> fromtime >> totime;
        }
    }
}