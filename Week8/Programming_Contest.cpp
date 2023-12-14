#include<bits/stdc++.h>
using namespace std;

#define MAX_FIRST 100004
#define MAX_SECOND 86400

int total_number_submissions = 0;
int number_error_submission = 0;

map<string, int> number_error__submission_of_user ;
map<string, int> total_point_of_user ;
map<pair<string, string>, int> point_of_user_at_problem;
map<int, int> number_submission_at;
int number_submission_until[MAX_SECOND];

int convert_to_second(string time) {
     //  HH:MM:SS
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h*3600 + m*60 + s;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int point;
    string user_id, problem_id, time_point, status;
    
    cin >> user_id;
    while (user_id != "#") {
        total_number_submissions += 1;
        cin >> problem_id >> time_point >> status >> point;

        if (status == "ERR") {
            number_error_submission += 1;
            number_error__submission_of_user[user_id] += 1;
        }
        else {
            int problem_point = point_of_user_at_problem[{user_id, problem_id}];
            if (point > problem_point) {
                total_point_of_user[user_id] += point - problem_point;
                point_of_user_at_problem[{user_id, problem_id}] = point;
            }
        }
        // time
        number_submission_at[convert_to_second(time_point)] += 1;

        cin >> user_id;
    }

    int sum = 0;
    for (int i = 0; i < 86400; i++) {
        sum += number_submission_at[i];
        number_submission_until[i] += sum;
    }

    string query;
    cin >> query;

    while (query != "#") {
        if (query == "?total_number_submissions")
            cout << total_number_submissions << "\n";
        else if (query == "?number_error_submision")
            cout << number_error_submission << "\n";
        else if (query == "?number_error_submision_of_user") {
            string user_id;
            cin >> user_id;
            cout << number_error__submission_of_user[user_id] << "\n";
        }
        else if (query == "?total_point_of_user") {
            string user_id;
            cin >> user_id;
            cout << total_point_of_user[user_id] << "\n";
        }
        else if (query == "?number_submission_period") {
            string start_time, end_time;
            cin >> start_time >> end_time;
            cout << number_submission_until[convert_to_second(end_time)] - number_submission_until[convert_to_second(start_time) - 1] << "\n";
        }

        cin >> query;
    }

}