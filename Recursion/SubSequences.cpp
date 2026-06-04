#include<bits/stdc++.h>
using namespace std;

void generateBinarySeq(int n, string s,vector<string>& ans){
    if(s.length() == n){
        ans.push_back(s);
        return;
    }

    generateBinarySeq(n, s + "0", ans);

    if(s.empty() || s.back() != '1'){
        generateBinarySeq(n, s + "1", ans);
    }
}


void populateAns(int n,vector<string>& ans,string s = "",int l_count = 0, int r_count = 0){
    if(l_count > n || r_count > n || l_count < r_count){
        return;
    }
    if(s.length() == 2*n){
        ans.push_back(s);
        return;
    }
    populateAns(n,ans, s + "(", l_count+1, r_count);
    populateAns(n,ans, s + ")", l_count, r_count+1);
}
vector<string> generateParenthesis(int n){
    vector<string> ans;
    populateAns(n, ans);
    return ans;
}

void generatePowerSet(string s, vector<string>& ans, string seq ="", int i=0){
    if(i == s.length()){
        ans.push_back(seq);
        return;
    }
    generatePowerSet(s,ans,seq + s[i], i+1);
    generatePowerSet(s, ans, seq, i+1);
}

int countSubSequenceWithSumK(vector<int>& nums, int target, int sum=0, int i=0){
    int count = 0;
    if(i == nums.size()){
        if(sum == target){
            return 1;
        }
        return 0;
    }
    
    count += countSubSequenceWithSumK(nums, target, sum + nums[i], i+1);
    count += countSubSequenceWithSumK(nums, target, sum , i+1);
    return count;
}

bool checkSubSequenceWithK(vector<int>& nums, int target, int sum=0, int i=0){
    if(i == nums.size()){
        if(sum == target){
            return true;
        }
        return false;
    }

    return checkSubSequenceWithK(nums, target, sum + nums[i], i+1) || checkSubSequenceWithK(nums, target, sum , i+1);
}


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

// sort the numbers after the function to get final answer
void SumOfEachSubset(vector<int>& nums,vector<int>& ans,int sum=0, int i=0){
    if(i == nums.size()){
        ans.push_back(sum);
        return;
    }

    SumOfEachSubset(nums, ans, sum+nums[i], i+1);
    SumOfEachSubset(nums, ans, sum, i+1);
}


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

unordered_map<char,string> NtoL = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};

void populateLetterCombAns(const string& digits, vector<string>& ans,string& seq,int i=0, int j=0){
    if(i == digits.length()){
        ans.push_back(seq);
        return;
    }

    const string& mapped = NtoL[digits[i]];
    if(j == mapped.length()){
        return;
    }

    seq.push_back(mapped[j]);
    populateLetterCombAns(digits, ans, seq, i+1, 0);
    seq.pop_back();
    populateLetterCombAns(digits, ans, seq , i, j+1);
}
vector<string> letterCombinations(string digits){
    if(digits.length() == 0)
        return {};
    vector<string> ans;
    string seq;
    populateLetterCombAns(digits, ans, seq);
    return ans;
}


int main(){
    vector<string> ans;
    vector<vector<int>> matrixans;
    vector<int> vecans;
    vector<int> nums = {1,2,2};

    ans = letterCombinations("7");
    
    /*
    cout<<vecans.size()<<"\n";
    for(auto x:vecans){
        cout<<x<<" ";
    }
    /*
    
    /*
    cout<<matrixans.size()<<"\n";
    for(auto x:matrixans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    */

    /**/
    cout<<ans.size()<<"\n";
    for(auto x:ans){
        cout<<x<<" ";
    }
    /**/
}