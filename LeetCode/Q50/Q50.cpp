#include<bits/stdc++.h>
using namespace std;

double myPow(double x,long long n){
    if(n == 0){
        return 1;
    }
    if( n < 0){
        x = 1 / x;
        n = -n;
    }
    double half = myPow(x, n /2);
    if(n % 2 == 0){
        return half * half;
    }else{
        return x * half * half;
    }
}

int main(){
    cout<<myPow(2,-2);
}