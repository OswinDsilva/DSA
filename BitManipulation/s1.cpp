#include<bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i) {
    return n & (1 << i);
}

bool isOdd(int n) {
    return n % 2 != 0;
}

bool isPowerOfTwo(int n) {
    if(n <= 0)
        return false;
    return (n & (n-1)) == 0;
}

int countSetBits(int n) {
    int count = 0;
    while(n > 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int setRightMostBit(int n){
    if(n == 0)
        return 1;
    if((n & (n+1)) == 0)
        return n;
    return n | n+1;
}

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    bool negative = (dividend < 0) ^ (divisor < 0);

    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);

    long long quotient = 0;

    for (int i = 31; i >= 0; i--) {
        if ((dvs << i) <= dvd) {
            dvd -= (dvs << i);
            quotient += (1LL << i);
        }
    }

    return negative ? -quotient : quotient;
}