#include<bits/stdc++.h>
using namespace std;

string code, dat_of_birth, father_code, mother_code, is_alive, zone_code;
int number_people; // số người 
int max_unrelated_people = 0; // so luong người  k cha me
int number_people_at[1095405];
map<int, int> number_people_born_at; // so nguoi sinh ra tai thoi diem  
map<string, pair<string, string>> parent_of; // thong tin cha me 
map<string, int> ancestor_count; // so to tien 
map<string, bool> unrelated; // kiem tra co người liên quan không. (không thì là true)
map<pair<string, string>, vector<string>> child_of; // danh sách con của 1 cặp cha mẹ 

int date_Convert(string date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));
    return y*372 + m*31 + d;
}

int ancestor_count_most(string id) {
    int count = 0;
    string fa = parent_of[id].first;
    string mo = parent_of[id].second;

    if(fa != "0000000" && mo != "0000000" ) {
        count +=1;
        count +=max(ancestor_count_most(fa), ancestor_count_most(mo));
    }
    ancestor_count[id] = count;
    return count;
}

    string s;
void input() {
    cin >> s;
    while( s != "*") {

        cin >> dat_of_birth >> father_code >> mother_code >> is_alive>> zone_code ;
       
        code = s;
       
        number_people += 1;
        number_people_born_at[date_Convert(dat_of_birth)] += 1;
        parent_of[code] = {father_code, mother_code};


        if (father_code == "0000000" && mother_code == "0000000") {
            max_unrelated_people ++;
            unrelated[code] = true;
        }else {
            child_of[{father_code, mother_code}].push_back(code);
            unrelated[code] = false;

            if(child_of[{father_code, mother_code}].size() > 2 || unrelated[father_code] == false || unrelated[mother_code] == false ) {

                if(unrelated[father_code] == true || unrelated[mother_code] == true ) {

                    unrelated[mother_code] = false;
                    unrelated[father_code] = false; 
                    max_unrelated_people -= 2;
                

                    for (auto a : child_of[{father_code, mother_code}])
                    {
                        unrelated[a] = true;
                        max_unrelated_people ++ ;
                    }
                }
                else {
                    unrelated[code] = true;
                    max_unrelated_people += 1;
                }
            }
        }
        cin >> s;
    }

    int sum = 0;
    for(int i = 0; i < 1095405; ++i ) {
        sum += number_people_born_at[i];
        number_people_at[i] = sum ; 
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    string q;
    cin >> q;
    while(q != "***") {
       if (q == "NUMBER_PEOPLE"){
            cout << number_people << "\n";
       }
        else if (q == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;
            cout << number_people_born_at[date_Convert(date)] << "\n";
        }
        else if (q == "MOST_ALIVE_ANCESTOR") {
            string code;
            cin >> code;
            if (ancestor_count[code] == 0)
                cout << ancestor_count_most(code) << "\n";
            else
                cout << ancestor_count[code] << "\n";
        }
        else if (q == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string time_start, time_end;
            cin >> time_start >> time_end;
            cout << number_people_at[date_Convert(time_end)] - number_people_at[date_Convert(time_start) - 1] << "\n";
        }
        else if (q == "MAX_UNRELATED_PEOPLE") {
            cout << max_unrelated_people << "\n";
        }
        cin >> q;
    }

    return 0;
}