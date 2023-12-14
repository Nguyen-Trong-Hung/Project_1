#include <iostream>
#include <queue>
#include <set>

using namespace std;

// UCLN cua a va b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// kiem tra dieu kien
int waterJug(int a, int b, int c) {
    if (c > max(a, b))
        return -1;

    if (c % gcd(a, b) != 0)
        return -1;

    queue<pair<int, int>> q; // lưu trang thai cua 2 binh nuoc 
    set<pair<int, int>> visited; // trang thai da duyet qua 

    q.push({0, 0});
    visited.insert({0, 0});

    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == c || y == c) {
                return steps;
            }

        // x không rỗng , y không đầy
            if (x != 0 && y != b) {
                int pour = min(x, b - y);
                if (visited.find({x - pour, y + pour}) == visited.end()) {
                    q.push({x - pour, y + pour});
                    visited.insert({x - pour, y + pour});
                }
            }

        // y không rỗng , x không đầy
            if (y != 0 && x != a) {
                int pour = min(a - x, y);
                if (visited.find({x + pour, y - pour}) == visited.end()) {
                    q.push({x + pour, y - pour});
                    visited.insert({x + pour, y - pour});
                }
            }

        // x không đầy , và TH chưa có trường hợp trong tập visited => đổ đầy nước vào x
            if (x != a && visited.find({a, y}) == visited.end()) {
                q.push({a, y});
                visited.insert({a, y});
            }
        // y không đầy , và chưa có trường hợp trong tập visited => đổ đầy nước vào y
            if (y != b && visited.find({x, b}) == visited.end()) {
                q.push({x, b});
                visited.insert({x, b});
            }

        // x không rỗng , chưa có trường hợp trong tập visited => đổ đầy nước vào x
            if (x != 0 && visited.find({0, y}) == visited.end()) {
                q.push({0, y});
                visited.insert({0, y});
            }

            if (y != 0 && visited.find({x, 0}) == visited.end()) {
                q.push({x, 0});
                visited.insert({x, 0});
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int result = waterJug(a, b, c);
    cout << result << endl;

    return 0;
}
