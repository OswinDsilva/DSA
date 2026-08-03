#include<bits/stdc++.h>
using namespace std;

int fruitBaskets(vector<int> fruits){
    int n = fruits.size();
    int start = 0;
    int end = 0;
    int maxlen = INT_MIN;
    unordered_map<int, int> lastOccurence;
    while(end < n){
        if(lastOccurence.find(fruits[end]) != lastOccurence.end() || lastOccurence.size() < 2){
            lastOccurence[fruits[end]] = end;
            maxlen = max(maxlen, end-start+1);
            end++;
        }else{
            start = lastOccurence[fruits[start]];
            lastOccurence.erase(fruits[start]);
            start++;
        }

    }
    return maxlen;
}

int characterReplacement(string s, int k) {
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxf = 0;
    int maxlen = 0;
    vector<int> freqs(26,0);
    while(right < n){
        char curr = s[right];
        freqs[curr - 'A']++;
        maxf = max(maxf, freqs[curr - 'A']);
        int len = right - left + 1;
        if(len - maxf <= k){
            maxlen = max(maxlen, len);
        }else{
            freqs[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return maxlen;
}

int numberOfSubstrings(string s) {
    int n = s.length();
    int count =0;
    int left = 0;
    int right = 0;
    unordered_map<char,int> freqs;
    while(right < n){
        if(freqs.find(s[right]) == freqs.end())
            freqs[s[right]] = 1;
        else{
            freqs[s[right]]++;
        }
        while(freqs.size() == 3){
            count += n - right;
            freqs[s[left]]--;
            if(freqs[s[left]] == 0){
                freqs.erase(s[left]);
            }
            left++;
        }
        right++;
    }
    return count;
}

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int maxScore = 0;
    int score = 0;
    for(int i=0;i<k;i++){
        score += cardPoints[i];
    }
    maxScore = score;
    for(int i=0;i<k;i++){
        score -= cardPoints[k-i-1];
        score += cardPoints[n-1-i];
        maxScore = max(score, maxScore);
    }
    return maxScore;
}
