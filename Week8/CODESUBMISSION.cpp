#include <bits/stdc++.h>
using namespace std;

string userId, query;
unordered_map<string, int> totalUserPoints;
unordered_map<string, int> errUserSubmissions;
set<int> timeArr;
int soBai = 0, baiNopLoi = 0, noptronggiaidoan[90000];
void Sum()
{
    int temp = 0;
    for (int t : timeArr)
    {
        noptronggiaidoan[t] += temp;
        temp = noptronggiaidoan[t];
    }
    soBai = temp;
    for (int i = 1; i <= 86400; ++i)
    {
        if (!noptronggiaidoan[i]) noptronggiaidoan[i] = noptronggiaidoan[i - 1];
    }
}

int chuyentime(string time)
{
    return ((time[0] - 48) * 10 + (time[1] - 48)) * 3600 + ((time[3] - 48) * 10 + (time[4] - 48)) * 60 + (time[6] - 48) * 10 + (time[7] - 48);
}


int main()
{
    cin >> userId;
    while (userId != "#")
    {
        string vande, time, trangthai;
        int point;
        cin >> vande >> time >> trangthai >> point;

        if (trangthai == "ERR")
        {
            baiNopLoi++;
            errUserSubmissions[userId]++;
        }
        else if (totalUserPoints[userId + vande] < point)
        {
            totalUserPoints[userId] += point - totalUserPoints[userId + vande];
            totalUserPoints[userId + vande] = point;
        }

        noptronggiaidoan[chuyentime(time)]++;
        timeArr.insert(chuyentime(time));

        cin >> userId;
    }
    Sum();
    int maxTime = *(--timeArr.end());
    cin >> query;
    while (query != "#")
    {
        if (query == "?total_number_submissions")
            cout << soBai;
        else if (query == "?number_error_submision")
            cout << baiNopLoi;
        else if (query == "?number_error_submision_of_user")
        {
            string userId;
            cin >> userId;
            cout << errUserSubmissions[userId];
        }
        else if (query == "?total_point_of_user")
        {
            string userId;
            cin >> userId;
            cout << totalUserPoints[userId];
        }
        else if (query == "?number_submission_period")
        {
            string time1, time2;
            cin >> time1 >> time2;
            int t1 = chuyentime(time1), t2 = chuyentime(time2);
            cout << noptronggiaidoan[t2] - noptronggiaidoan[t1 - 1];
        }
        cout << "\n";

        cin >> query;
    }
}