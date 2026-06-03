#include<bits/stdc++.h>
using namespace std;


int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int l_n = landStartTime.size();
    int w_n = waterStartTime.size();

    int minL = INT_MAX;
    int landFirstTime = INT_MAX;
    for(int i=0;i<l_n;i++){
        minL = min(minL, landStartTime[i] + landDuration[i]);
    }
    for(int i=0;i<w_n;i++){
        landFirstTime = min(landFirstTime, max(minL, waterStartTime[i]) + waterDuration[i]);
    }

    int minW = INT_MAX;
    int waterFirstTime = INT_MAX;
    for(int i=0; i<w_n;i++){
        minW = min(minW, waterStartTime[i] + waterDuration[i]);
    }
    for(int i=0;i<l_n;i++){
        waterFirstTime = min(waterFirstTime, max(minW, landStartTime[i]) + landDuration[i]); 
    }

    return min(landFirstTime, waterFirstTime);
}

int main(){
    vector<int> landStartTime = {2,8};
    vector<int> waterStartTime = {6};
    vector<int> landDuration = {4,1};
    vector<int> waterDuration = {3};
    cout<<earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
}