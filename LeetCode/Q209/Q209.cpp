/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

#include<bits/stdc++.h>
using namespace std;

// Sliding Window approach, optimal O(n)
int minSubArrayLen(int target,vector<int>& nums){
    int l=0,r=0;
    int n = nums.size();
    int sum=nums[l];
    int min_len = INT_MAX;
    while(r < n){
        if(sum >= target){
            min_len = min(min_len, r-l+1);
            sum -= nums[l++];
        }else{
            r++;
            if(r < n){
                sum += nums[r];
            }
        }
    }
    if(min_len == INT_MAX)
        return 0;
    return min_len;
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    cout<<minSubArrayLen(7,nums);
}