#include <bits/stdc++.h>

using namespace std;

string s1, s2, tmp;
int sotien, solenh, chuky = 0;
long total_sotien;

map<string, int> tienvao;
set<string> danhsachnganhang;
map<string, set<string>> giaodich;

void input()
{
    cin >> s1;
    while (s1 != "#")
    {
        solenh += 1;

        cin >> s2 >> sotien >> tmp >> tmp;

        // list_sorted
        danhsachnganhang.insert(s1);
        danhsachnganhang.insert(s2);

        // total_sotien
        total_sotien += sotien;
        tienvao[s1] += sotien;

        // giaodich info
        giaodich[s1].insert(s2);
        cin >> s1;
    }
}

map<string, int> visited;
void inspect_cycle(string tmp_begin, int k, string begin)
{
    if (k == 1)
    {
        for (auto it : giaodich[tmp_begin])
            if (it == begin && visited[it] == 0)
            {
                chuky = 1;
                return;
            }
    }
    else
        for (auto it : giaodich[tmp_begin])
        {
            if (visited[it] == 0)
            {
                visited[it] = 1;
                inspect_cycle(it, k - 1, begin);
                visited[it] = 0;
            }
        }
}

void querying()
{
    string query;
    cin >> query;

    while (query != "#")
    {
        if (query == "?number_transactions")
            cout << solenh << endl;
        else if (query == "?total_money_transaction")
            cout << total_sotien << endl;
        else if (query == "?list_sorted_accounts")
        {
            for (auto it : danhsachnganhang)
                cout << it << " ";
            cout << endl;
        }
        else if (query == "?total_money_transaction_from")
        {
            cin >> tmp;
            cout << tienvao[tmp] << endl;
        }
        else if (query == "?inspect_cycle")
        {
            int k;
            cin >> tmp >> k;
            chuky = 0;
            inspect_cycle(tmp, k, tmp);
            cout << chuky << endl;
        }
        cin >> query;
    }
}

int main()
{
    input();
    querying();
    return 0;
}