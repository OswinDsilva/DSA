/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them
*/

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s){
    int n = s.length();
    vector<vector<char>> buckets(n+1);
    int freq[128] = {0};
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }
    for(int i=0;i<128;i++){
        if(freq[i] != 0)
            buckets[freq[i]].push_back(i);
    }
    string res = "";
    for(int i=n;i>0;i--){
        for(int j=0;j<buckets[i].size();j++){
            for(int k=0;k<i;k++)
            res += buckets[i][j];
        }
    }
    return res;
}

int main(){
    string s = "tree";
    string result = frequencySort(s);
    for (char c : result) {
        cout << c << " ";
    }
}