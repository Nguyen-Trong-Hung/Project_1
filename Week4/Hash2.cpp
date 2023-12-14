#include <iostream>
#include <string>
using namespace std;

int n, m;
string s[1000];
int r[201];

int hash_code(string str)
{
    int hashcode = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        hashcode += str[i] * r[len - i - 1];
        hashcode %= m;
    }
    return hashcode;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    r[0] = 1;
    for (int i = 1; i <= 200; i++)
    {
        r[i] = 256 * r[i - 1];
        r[i] %= m;
    }
    for (int i = 0; i < n; i++)
    {
        cout << hash_code(s[i]) << endl;
    }
}