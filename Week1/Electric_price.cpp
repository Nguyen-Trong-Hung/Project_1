//C++ 
#include <bits/stdc++.h> 
#include<iomanip>
#include<iostream>
int main() 
{ 
    int Ecount;
    std::cin >> Ecount;
    double price;
    if(Ecount <= 50){
        price = 0;
    }
    else if(Ecount <= 100){
        price = -1.1*(1.728*50 + 1.786*(Ecount - 50) - 70*1.728)*1000;
    }
        else if(Ecount <= 300){
            price = -1.1*(1.728*50+1.786*50-1.728*100)*1000;
        }
            else if(Ecount <= 400){
                price = -1.1*(50*1.728+50*1.786-100*1.728+100*2.612+(Ecount-300)*2.919-(Ecount-200)*2.612)*1000;
            }
                else if(Ecount <= 700){
                    price = -1.1*(50*1.728+50*1.786+100*2.919-100*2.612-100*1.728+(Ecount-400)*(3.015-3.111))*1000;
                }
                    else
                        price = -1.1*(50*1.728+50*1.786+100*2.919-100*2.612-100*1.728+(Ecount-400)*3.015-300*3.111-(Ecount-700)*3.457)*1000;
    std::cout << std::fixed << std::setprecision(2) << price;
}
