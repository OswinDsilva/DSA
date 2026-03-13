#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int squareRoot(int n){
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = (low+high)/2;
        if(1LL*mid*mid > n)
            high = mid-1;
        else
            low = mid + 1;
    }
    return high;
}

int NthRoot(int n,int m){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid = (low+high)/2;
        ll prod = 1;
        for(int i =0;i<n;i++){
            prod *= mid;
        }
        if(prod == m)
            return mid;
        if(prod > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


bool CheckPossible(vector<int>& stalls,int min,int k){
    int n = stalls.size();
    int last_cow_stall = stalls[0];
    k--;
    for(int i=1;i<n && k > 0;i++){
        if(stalls[i] - last_cow_stall >= min){
            k--;
            last_cow_stall = stalls[i];
        }
    }
    if(k>0)
        return false;
    return true;
}
int AggressiveCows(vector<int>& stalls,int k){
    int n = stalls.size();
    if(k > n)
        return -1;
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];
    while(low <= high){
        int mid = (low+high)/2;
        if(!CheckPossible(stalls,mid,k))
            high = mid-1;
        else
            low = mid+1;
    }
    return high;
}

int main(){
    vector<int> test={4,2,1,3,6};
    cout<<AggressiveCows(test,2);
}