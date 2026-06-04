#include<bits/stdc++.h>
using namespace std;

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
    ans = letterCombinations("7");
    cout<<ans.size()<<"\n";
    for(auto x:ans){
        cout<<x<<" ";
    }
}