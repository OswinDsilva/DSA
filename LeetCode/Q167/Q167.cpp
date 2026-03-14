/*
14/3/2026
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Binary Search approach , not optimal for this qn, O(nlogn)
int BinarySearchForK(vector<int>& nums,int k, int low, int high){
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == k){
            return mid;
        }
        if(nums[mid] < k){
            low = mid+1; 
        }else{
            high = mid-1;
        }   
    }
    return -1;
}
vector<int> twoSumBinarySearch(vector<int>& numbers, int target){
    int n = numbers.size();
    for(int i=0;i<n;i++){
        int idx = BinarySearchForK(numbers,target-numbers[i],i+1,n-1);
        if(idx != -1){
            return {i+1,idx+1};
        }
    }
    return {};
}

//Two pointer approach, optimal , O(n)
vector<int> twoSumTwoPointers(vector<int>& numbers, int target){
    int n = numbers.size();
    int l=0,r=n-1;
    while(l < r){
        int compute = numbers[l] + numbers[r];
        if(compute == target)
            return {l+1,r+1};
        if(compute < target){
            l++;
        }else{
            r--;
        }
    }
    return {};
}



int main(){
    vector<int> nums = {2,3,4};
    vector<int>ans = twoSumTwoPointers(nums,6);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}