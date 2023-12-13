#include<bits/stdc++.h>
#include<iomanip>

int main(){
    double a,b,c;
    std::cin >> a >> b >> c;
    double delta = b*b - 4*a*c;
    if(delta < 0){
        std::cout << "NO SOLUTION";
    }
    else if(delta == 0){
        std::cout << std::fixed << std::setprecision(2) << (-b)/(2*a);
    }
        else{
            delta = sqrt(delta);
            double x1 = (-b-delta)/(2*a),x2 = (-b+delta)/(2*a);
            if(x1 < x2)
                std::cout << std::fixed << std::setprecision(2) << x1 << " " << x2;
            else 
                std::cout << std::fixed << std::setprecision(2) << x2 << " " << x1;
        }
}
