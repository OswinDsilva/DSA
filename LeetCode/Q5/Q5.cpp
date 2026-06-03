/*
Given a string s, return the longest in s.
18/03/26
*/

#include<bits/stdc++.h>
using namespace std;


int checkPalindrome(string s,int c1, int c2 = -1){
    int n = s.length();
    int len = 0;
    if (c2 != -1){
        while(c1 >= 0 && c2 < n){
            if(s[c1] != s[c2])
                break;
            len += 2;
            c1--;
            c2++;
        }
    }else{
        int l=c1-1, r=c1+1;
        len = 1;
        while(l >= 0 && r < n){
            if(s[l] != s[r]){
                break;
            }
            len += 2;
            l--;
            r++;
        }
    }
    return len;
}

string longestPalindrome(string s){
    string pal;
    int max_len=0;
    int start = 0, end=0;
    int n = s.length();
    for(int c=0;c<n;c++){
        int len1 = checkPalindrome(s,c);
        int len2 = checkPalindrome(s,c,c+1);
        if(len1 > len2){
            if(len1 > max_len){
                max_len = len1;
                start = c - (len1-1)/2;
                end = c + (len1-1)/2;
            }
        }else{
            if(len2 > max_len){
                max_len = len2;
                start = c - (len2)/2 + 1;
                end = c + (len2)/2 ;
            }
        }
    }
    pal = string(s.begin()+start,s.begin()+end+1);
    return pal;
}


int main(){
    string s = "aaba";
    cout<<longestPalindrome(s);
}