#include <bits/stdc++.h>

using namespace std;
string text;

int main()
{
    while (getline(cin, text))
    {
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        cout << text << endl;
    }
    return 0;
}