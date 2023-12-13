#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        std::cin >> a[i];
    }
    int count1 = 0,count2 = 0;
    for(int i = 0;i < n;i++){
        if(a[i] % 2 != 0)
            count1++;
        else
            count2++;
    }
    std::cout << count1 << " " << count2;
}
