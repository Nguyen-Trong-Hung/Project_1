#include <bits/stdc++.h>
using namespace std;

string code, query;
unordered_map<string, int> dobPeopleMap;
int songuoi = 0, sinhtruoc[1100000], bo[100005], me[100005], nguoi[100005];

void tong()
{
    for (int i = 1; i <= 1100000; ++i)
        sinhtruoc[i] += sinhtruoc[i - 1];
}
int chuyenNgay(string date)
{
    return ((date[0] - 48) * 1000 + (date[1] - 48) * 100 + (date[2] - 48) * 10 + (date[3] - 48)) * 365 + ((date[5] - 48) * 10 + (date[6] - 48)) * 30 + (date[8] - 48) * 10 + (date[9] - 48);
}

int ma_Songuyen(string code)
{
    int temp = 0;
    for (int i = 0; i < code.length(); ++i)
    {
        temp = temp * 10 + (code[i] - '0');
    }
    return temp;
}


int mostAncestor(int code)
{
    if (!code)
        return 0;
    int momSide = mostAncestor(me[code]);
    int dadSide = mostAncestor(bo[code]);
    return max(momSide, dadSide) + 1;
}

int main()
{
    cin >> code;
    while (code != "*")
    {
        string dob, FCode, MCode, maquocgia;
        char isAlive;
        cin >> dob >> FCode >> MCode >> isAlive >> maquocgia;

        songuoi++;

        dobPeopleMap[dob]++;

        bo[ma_Songuyen(code)] = ma_Songuyen(FCode);
        me[ma_Songuyen(code)] = ma_Songuyen(MCode);
        nguoi[songuoi] = ma_Songuyen(code);

        sinhtruoc[chuyenNgay(dob)]++;

        cin >> code;
    }
    tong();
    cin >> query;
    while (query != "***")
    {
        if (query == "NUMBER_PEOPLE")
            cout << songuoi;
        else if (query == "NUMBER_PEOPLE_BORN_AT")
        {
            string date;
            cin >> date;
            cout << dobPeopleMap[date];
        }
        else if (query == "MOST_ALIVE_ANCESTOR")
        {
            string code;
            cin >> code;
            cout << mostAncestor(ma_Songuyen(code)) - 1;
        }
        else if (query == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string fromDate, toDate;
            cin >> fromDate >> toDate;
            int t1 = chuyenNgay(fromDate), t2 = chuyenNgay(toDate);
            cout << sinhtruoc[t2] - sinhtruoc[t1 - 1];
        }
        else if (query == "MAX_UNRELATED_PEOPLE")
        {
            int k = 0, j = 0;
            for (int i : nguoi)
            {
                if (i)
                {
                    if (mostAncestor(i) % 2 == 0)
                        k++;
                    else
                        j++;
                }
            }
            cout << max(k, j);
        }
        cout << "\n";

        cin >> query;
    }
}