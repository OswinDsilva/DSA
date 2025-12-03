#include<iostream>
#include<climits>
#include<cmath>

using std::cout;

//Count Digits
int Count(int n){
    if(n == 0)
        return 1;
    int count = 0;
    while(n > 0){
        n /= 10;
        count++;
    }
    return count;
}

//Reverse a Number (LeetCode 7.)
int reverse(int x) {
    int rev = 0;
    while(x != 0){
        if(rev > INT_MAX/10) return 0;
        if(rev < INT_MIN/10) return 0;
        rev = rev*10 + x%10;
        x /= 10;
    }
    return rev;
}

//Check if a number is a palindrome (LeetCode 9.)
bool isPalindrome(int x){
    if(x && x % 10 == 0)
        return false;
    int rev = 0;
    int temp = x;
    while(temp > rev){
        rev = rev*10 + temp%10;
        temp /= 10;
    }
    if(rev == temp || (rev/10 == temp))
        return true;
    else
        return false;
}

//GCD or HCF
int GCD(int a,int b){
    while(a != 0 && b != 0){
        int rem = a % b;
        a = b;
        b = rem;
    }
    if(a == 0)
        return b;
    else
        return a;
}

//Armstrong Number
bool Armstrong_Number(int x){
    int len = Count(x);
    int sum = 0;
    int temp = x;
    while(temp > 0){
        sum += pow(temp%10,len);
        temp /= 10;
    }
    if(x == sum)
        return true;
    else
        return false;
}

//Print all Divisors
void Divisors(int x){
    for(int i=1;i<= pow(x,0.5);i++){
        if(x % i == 0){
            cout<<i<<" ";
            if(x/i != i)
                cout<<x/i<<" ";
        }
    }
}

//Check for Prime
bool Prime(int x){
    if(x <= 1)
        return false;
    if(x == 2)
        return true;
    if(x%2 == 0)
        return false;
    for(int i = 3;i*i <= x;i += 2){
        if(x%i==0)
            return false;
    }
    return true;
}
