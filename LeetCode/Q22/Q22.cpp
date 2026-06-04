#include<bits/stdc++.h>
using namespace std;

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

int main(){
    vector<string> ans;
    ans = generateParenthesis(2);
    for(auto x: ans){
        cout<<x<<" ";
    }
}