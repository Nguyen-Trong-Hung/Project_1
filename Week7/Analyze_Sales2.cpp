#include <bits/stdc++.h>

using namespace std;

int main() {
    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
    map<string, map<string, int>> revenueofshop;
    map<string, int> timemoney;
    string cmd1;

    int numberorder = 0;
    int revenue = 0;
    while (true) {
        cin >> cmd1;
        if (cmd1 == "#") {
            break;
        }
        customerID = cmd1;
        cin >> productID >> price >> shopID >> timePoint;
        numberorder++;
        revenue += price;

        if (revenueofshop.count(shopID) == 0) {
            revenueofshop[shopID][customerID] = price;
        } else if (revenueofshop[shopID].count(customerID) == 0) {
            revenueofshop[shopID][customerID] = price;
        } else {
            revenueofshop[shopID][customerID] += price;
        }
        if(timemoney.count(timePoint) == 0){
            timemoney.insert({timePoint, price});
        }
        else{
            timemoney[timePoint] += price;
        }
    }

    string cmd2;
    while (cin >> cmd2) {
        if (cmd2 == "#") {
            break;
        } else if (cmd2 == "?total_number_orders") {
            cout << numberorder << "\n";
        } else if (cmd2 == "?total_revenue") {
            cout << revenue << "\n";
        } else if (cmd2 == "?revenue_of_shop") {
            string shop;
            cin >> shop;
            int money = 0;
            for (auto& order : revenueofshop[shop]) {
                money += order.second;
            }
            cout << money << "\n";
        } else if (cmd2 == "?total_consume_of_customer_shop") {
            string customer;
            string shop;
            cin >> customer >> shop;
            cout << revenueofshop[shop][customer] << "\n";
        } else if (cmd2 == "?total_revenue_in_period") {
            string fromtime;
            string totime;
            cin >> fromtime >> totime;
            // Tính tổng doanh thu trong khoảng thời gian từ fromtime đến totime
            int totalRevenue = 0;
            for (auto& Tmoney : timemoney) {
                if (Tmoney.first >= fromtime && Tmoney.first <= totime) {
                    totalRevenue += Tmoney.second;
                }
            }
            cout << totalRevenue << "\n";
        }
    }

    return 0;
}