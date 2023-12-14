#include <bits/stdc++.h>
using namespace std;
// customer - product - cost - shop - time

int sodonhang, doanhthu;

map<string, int> doanhthucuahang;
map<pair<string, string>, int> cuahangdoanhthu;

int money_time[86401];
int sotiendenkhi[86400];

string shop, cus, buy_time, tmp;
int cost;

int chuyendoithoigian(string time)
{
    return (time[0] * 10 + time[1]) * 3600 + (time[3] * 10 + time[4]) * 60 + time[6] * 10 + time[7] - 1933008;
}

void input()
{
    cin >> cus;
    while (cus != "#")
    {
        sodonhang += 1;
        cin >> tmp >> cost >> shop >> buy_time;

        doanhthu += cost;
        doanhthucuahang[shop] += cost;
        cuahangdoanhthu[{shop, cus}] += cost;

        money_time[chuyendoithoigian(buy_time)] += cost;

        cin >> cus;
    }

    int tmp_sum = 0;
    for (int i = 0; i < 86400; i++)
    {
        tmp_sum += money_time[i];
        sotiendenkhi[i] = tmp_sum;
    }
}

int revenue_period(string thoigianbatdau, string thoigianketthuc)
{
    int start = chuyendoithoigian(thoigianbatdau);
    int end = chuyendoithoigian(thoigianketthuc);
    return sotiendenkhi[end] - sotiendenkhi[start - 1];
}

void querying()
{
    string query;
    cin >> query;

    while (query != "#")
    {
        if (query == "?total_number_orders")
            cout << sodonhang << endl;
        else if (query == "?total_revenue")
            cout << doanhthu << endl;
        else if (query == "?revenue_of_shop")
        {
            cin >> tmp;
            cout << doanhthucuahang[tmp] << endl;
        }
        else if (query == "?total_consume_of_customer_shop")
        {
            cin >> cus >> shop;
            cout << cuahangdoanhthu[{shop, cus}] << endl;
        }
        else if (query == "?total_revenue_in_period")
        {
            string thoigianbatdau, thoigianketthuc;
            cin >> thoigianbatdau >> thoigianketthuc;
            cout << revenue_period(thoigianbatdau, thoigianketthuc) << endl;
        }
        cin >> query;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    querying();
    return 0;
}