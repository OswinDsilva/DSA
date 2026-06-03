#include<bits/stdc++.h>
using namespace std;


int HelperAtoi(string& s,int i,long long num, int sign,bool FoundDigits,bool FoundSign){ 
    if(i == s.length())
        return sign * num;
    if(!FoundDigits){
        if(s[i] == ' ' && !FoundSign)
            return HelperAtoi(s,i+1,num,sign,FoundDigits,FoundSign);
        if(s[i] == '-' && !FoundSign)
            return HelperAtoi(s,i+1,num,-1,FoundDigits,true);
        if(s[i] == '+' && !FoundSign)
            return HelperAtoi(s,i+1,num,1,FoundDigits,true);
        if(isdigit(s[i])){
            return HelperAtoi(s,i+1,num * 10 + (s[i] - '0'),sign,true,true);
        }
        return 0;
    }else if(isdigit(s[i])){
        int digit = s[i] - '0';
        int limit = (sign == -1)?8:7;
        if(num > INT_MAX/10 || (num == INT_MAX/10 && digit > limit))
            return (sign == -1)?INT32_MIN:INT32_MAX;
        return HelperAtoi(s,i+1,num * 10 + digit,sign,FoundDigits,FoundSign);
    }
    return sign * num;
}
int myAtoi(string s) {
    return HelperAtoi(s,0,0,1,false,false);
}

int main(){
    cout<<myAtoi("123");
}