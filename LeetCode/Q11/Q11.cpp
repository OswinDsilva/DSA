#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int area = INT_MIN;
    int left = 0, right = n-1;
    while(left < right){
        area = max(area, min(height[left],height[right]) * (right-left));
        if(height[left] > height[right]){
            right--;
        }else{
            left++;
        }
    }
    return area;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
}