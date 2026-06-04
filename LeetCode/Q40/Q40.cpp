#include<bits/stdc++.h>
using namespace std;

void populateCombSumAns2(vector<vector<int>>& ans, vector<int>& candidates, int target, vector<int>& seq, int i=0){
    if(target < 0)
        return;
    if(target == 0){
        ans.push_back(seq);
        return;
    }
    if(i == candidates.size()){
        return;
    }
    seq.push_back(candidates[i]);
    populateCombSumAns2(ans, candidates, target-candidates[i], seq, i+1);
    seq.pop_back();
    while(i < candidates.size()-1 && candidates[i] == candidates[i+1]){
        i=i+1;
    }
    populateCombSumAns2(ans, candidates, target, seq, i+1);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> seq;
    sort(candidates.begin(), candidates.end());
    populateCombSumAns2(ans, candidates, target, seq);
    return ans;
}

int main(){
    vector<vector<int>> matrixans;
    vector<int> nums = {10,1,2,7,6,1,5};
    matrixans = combinationSum2(nums, 8);
    cout<<matrixans.size()<<"\n";
    for(auto x:matrixans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}