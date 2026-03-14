/*
14/03/2026
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
*/

#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int mySqrt(int x){
    if(x < 2) 
        return x;
    ll low = 1,high = x/2;
    while(low <= high){
        ll mid = (low+high)/2;
        ll computed = 1LL*mid*mid;
        if(computed == x)
            return mid;
        if(computed < x)
            low = mid+1;
        else
            high = mid-1;
    }
    return high;
}

int main(){
    cout<<mySqrt(1);
}