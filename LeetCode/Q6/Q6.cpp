#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows){
    if(numRows == 1){
        return s;
    }

    int n = s.length();
    int difference  = 2*(numRows) - 2;
    string ans = "";

    for(int i=0;i<numRows;i++){
        for(int j=i; j<n;j += difference){
            ans += s[j];

            int diagonal = j + difference - (2*i);
            if((i == 0) || (i == (numRows - 1)) || diagonal >= n )
                continue;
            ans += s[diagonal];
        }
    }
    return ans;
}

int main(){
    string s = "PAYPALISHIRING";
    cout<<convert(s, 3);
}