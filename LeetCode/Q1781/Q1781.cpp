#include<bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int n = s.length();
    long long beautysum = 0;
    for(int i=0;i<n;i++){
        int freq[26]={0};
        char c_max = s[i];
        freq[s[i]-'a']++;
        for(int j=i+1;j<n;j++){
            freq[s[j]-'a']++;
            if(freq[s[j] - 'a'] > freq[c_max - 'a']){
                c_max = s[j];
            }
            int min_freq = INT_MAX;
            for(int k=0;k<26;k++){
                if(freq[k] < min_freq && freq[k] > 0){
                    min_freq = freq[k];
                }
            }
            beautysum += 1LL*freq[c_max - 'a'] - min_freq;
        }
    }
    return beautysum;
}

int main(){
    string s ="aabc";
    cout<<beautySum(s);
}