#include<bits/stdc++.h>
using namespace std;

void populateCombSumAns(vector<vector<int>>& ans, vector<int>& candidates, int target, vector<int>& seq , int sum=0, int i=0){
    if(sum > target){
        return;
    }
    if(sum == target){
        ans.push_back(seq);
        return;
    }
    if(i == candidates.size()){
        return;
    }
    seq.push_back(candidates[i]);
    populateCombSumAns(ans, candidates, target, seq, sum + candidates[i], i);
    seq.pop_back();
    populateCombSumAns(ans, candidates, target, seq, sum, i+1);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> seq;
    populateCombSumAns(ans, candidates, target, seq);
    return ans;
}

int main(){
    vector<vector<int>> matrixans;
    vector<int> nums = {2,3,6,7};
    matrixans = combinationSum(nums, 7);

    cout<<matrixans.size()<<"\n";
    for(auto x:matrixans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}