#include<bits/stdc++.h>
using namespace std;

int longestKDistinct(string s,int k){
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxLen = 0;
    unordered_map<char, int> freqs;
    while(right < n){
        freqs[s[right]]++;
        while(freqs.size() > k){
            freqs[s[left]]--;
            if(freqs[s[left]] == 0)
                freqs.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right-left+1);
        right++;
    }
    return maxLen;
}
int helperAtMostSubArrayCounts(vector<int>&nums, int k){
    int count = 0;
    int n = nums.size();
    int left = 0;
    int right = 0;
    unordered_map<int, int> freqs;
    while(right < n){
        freqs[nums[right]]++;
        while(freqs.size() > k){
            freqs[nums[left]]--;
            if(freqs[nums[left]] == 0)
                freqs.erase(nums[left]);
            left++;
        }
        count += right-left+1;
        right++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helperAtMostSubArrayCounts(nums,k) - helperAtMostSubArrayCounts(nums, k-1);
}

string minWindow(string s, string t) {
    string ans;
    int left = 0;
    int right = 0;
    int n = s.length();
    int minLen = INT_MAX;
    int minStart = 0;
    int lettersDone = 0;
    unordered_map<char, int> freqs;
    for(auto c : t){
        freqs[c]++;
    }
    while(right < n){
        if(freqs.find(s[right]) != freqs.end()){
            freqs[s[right]]--;
            if(freqs[s[right]] >= 0)
                lettersDone++;
        }

        while(lettersDone == t.length()){
            if(minLen > right-left+1){
                minLen = right-left+1;
                minStart = left;
            }
            if(freqs.find(s[left]) != freqs.end()){
                freqs[s[left]]++;
                if(freqs[s[left]] > 0)
                    lettersDone--;
            }
            left++;
        }
        right++;
    }
    if(minLen == INT_MAX){
        return "";
    }
    return s.substr(minStart, minLen);
}
