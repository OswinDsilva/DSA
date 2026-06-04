#include<bits/stdc++.h>
using namespace std;

void populateCombSumAns3(int k, int target,vector<vector<int>>& ans, vector<int>& seq, int i=1){
    if(target < 0 || seq.size() > k){
        return;
    }
    if(target == 0){
        if(seq.size() == k)
            ans.push_back(seq);
        return;
    }
    if(i > 9){
        return;
    }

    seq.push_back(i);
    populateCombSumAns3(k,target-i,ans,seq,i+1);
    seq.pop_back();
    populateCombSumAns3(k,target,ans,seq,i+1);
}
vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>> ans;
    vector<int> seq;
    populateCombSumAns3(k,n,ans,seq);
    return ans;
}
int main(){
    vector<vector<int>> matrixans;
    matrixans = combinationSum3(3,7);
    cout<<matrixans.size()<<"\n";
    for(auto x:matrixans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}