#include<bits/stdc++.h>
using namespace std;

void populateSubsetsWithDupAns(vector<int>& nums,vector<vector<int>>& ans,vector<int>& seq, int i=0){
    if(i == nums.size()){
        ans.push_back(seq);
        return;
    }

    seq.push_back(nums[i]);
    populateSubsetsWithDupAns(nums, ans, seq, i+1);
    seq.pop_back();
    while(i < nums.size() - 1 && nums[i] == nums[i+1]){
        i = i+1;
    }
    populateSubsetsWithDupAns(nums, ans, seq, i+1);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> seq = {};
    sort(nums.begin(), nums.end());
    populateSubsetsWithDupAns(nums, ans, seq);
    return ans;
}

int main(){
    vector<vector<int>> matrixans;
    vector<int> nums = {1,2,2};
    matrixans = subsetsWithDup(nums);
    cout<<matrixans.size()<<"\n";
    for(auto x:matrixans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}