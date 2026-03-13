#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int lowerBound(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}

int upperBound(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] <= x)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}

vector<int> FloorAndCeil(vector<int>& nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int floor=-1, ceil=-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] <= x)
            low = mid+1;
        else
            high = mid-1;
    }
    if(low > 0)
        floor = nums[low-1];
    low = 0;high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }
    if(low < n)
        ceil = nums[low];
    return {floor,ceil};
}

int countOccurences(vector<int>& nums, int x){
    return upperBound(nums,x) - lowerBound(nums,x);
}

int countRotations(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low < high){
        int mid = (low+high)/2;

        if(nums[mid] <= nums[high]){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> test ={4,5,6,7,0,1,2,3};
    cout<<countRotations(test);
}