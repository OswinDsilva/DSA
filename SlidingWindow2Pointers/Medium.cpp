#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int left = 0, right=n-1;
    int max_sum = 0;
    int sum = 0;
    int count = 0;
    while(left < right){
        if(cardPoints[left] > cardPoints[right]){
            sum += cardPoints[left];
        }
        else{
            sum += cardPoints[right];
        }
        if(count > k){

        }
    }
}