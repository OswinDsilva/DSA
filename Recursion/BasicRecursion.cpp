#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long binaryExponentHelper(long long base, long long power){
    const int mod = (1e9) + 7;
    if(power == 0){
        return 1;
    }
    if(power % 2 != 0){
        return (base * binaryExponentHelper((base*base) % mod, power/2)) % mod;
    }else{
        return binaryExponentHelper((base*base) % mod, power/2);
    }
}
int countGoodNumbers(long long n) {
    if(n == 0){
        return 1;
    }
    const int mod = (1e9) + 7;
    long long a = binaryExponentHelper(5,(n+1)/2) % mod;
    long long b = binaryExponentHelper(4,n/2) % mod;
    return (a * b) % mod;
}

void insert(stack<int>& s, int item){
    if(s.empty() || s.top() <= item){
        s.push(item);
        return;
    }

    int item2 = s.top();
    s.pop();
    insert(s,item);

    s.push(item2);
}
void sortStack(stack<int>& s){   
    if(s.empty()){
        return;
    }
    int item = s.top();
    s.pop();
    
    sortStack(s);
    insert(s, item);
}

void sendToBottom(stack<int>& s, int item){
    if(s.empty()){
        s.push(item);
        return;
    }
    int item2 = s.top();
    s.pop();

    sendToBottom(s, item);
    s.push(item2);
}
void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }
    int item = s.top();
    s.pop();

    reverseStack(s);
    sendToBottom(s, item);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(0);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}