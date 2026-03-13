#include<bits/stdc++.h>

using std::vector;
using std::cout;

using ll = long long;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;
    int ele1 = INT_MIN, c1 = 0;
    int ele2 = INT_MIN, c2 = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(c1 == 0 && nums[i] != ele2){
            c1 = 1;
            ele1 = nums[i];
        }else if(c2 == 0 && nums[i] != ele1){
            c2 = 1;
            ele2 = nums[i];
        }else if(nums[i] == ele1)
            c1++;
        else if(nums[i] == ele2)
            c2++;
        else{
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == ele1)
            c1++;
        if(nums[i] == ele2)
            c2++;
    }
    if(c1>n/3)
        result.push_back(ele1);
    if(c2>n/3)
        result.push_back(ele2);
    return result;
}

vector<vector<int>> threeSum(vector<int>&nums){
    vector<int> new_nums(nums.begin(),nums.end());
    sort(new_nums.begin(),new_nums.end());
    int n = new_nums.size();
    int i=0,j,k;
    vector<vector<int>> result;
    for(int i = 0;i<n;i++){
        if(i > 0 && new_nums[i] == new_nums[i-1])
            continue;
        j = i+1;
        k = n-1;
        while(j < k){
            if(new_nums[i] + new_nums[j] + new_nums[k]  < 0)
                j++;
            else if(new_nums[i] + new_nums[j] + new_nums[k] > 0)
                k--;
            else{
                result.push_back({new_nums[i],new_nums[j],new_nums[k]});
                j++;k--;
                while(j < k && new_nums[j] == new_nums[j-1])
                    j++;
                while(j < k && new_nums[k] == new_nums[k+1])
                    k--;
            }
        }
    }   
    return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> new_nums(nums.begin(), nums.end());
    sort(new_nums.begin(),new_nums.end());
    int n = new_nums.size();
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
        if(i > 0 && new_nums[i] == new_nums[i-1])
            continue;
        for(int j=i+1;j<n;j++){
            if(j > i+1 && new_nums[j] == new_nums[j-1])
                continue;
            int left = j+1;
            int right = n-1;
            while(left < right){
                ll sum = ll(new_nums[i]) +new_nums[j] + new_nums[left] + new_nums[right];
                if(sum < target)
                    left++;
                else if(sum > target)
                    right--;
                else{
                    result.push_back({new_nums[i],new_nums[j],new_nums[left],new_nums[right]});
                    left++;right--;
                    while(left < right && new_nums[left] == new_nums[left-1])
                        left++;
                    while(left < right && new_nums[right] == new_nums[right+1])
                        right--;
                }
            } 
        }
    }
    return result;
}

// In general, prefix[i] − prefix[j] = K
int SubArrayWithSumZero(vector<int>& nums){
    std::unordered_map<int,int> mpp;
    int n = nums.size();
    int sum = 0;
    int max_length = 0;
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(sum == 0)
            max_length = i+1;
        else{
            if(mpp.find(sum) != mpp.end())
                max_length = std::max(max_length, i - mpp[sum]);
            else
                mpp[sum] = i;
        }
    }
    return max_length;
}

int SubArraysWithXORK(vector<int>& nums, int k){
    std::unordered_map<int,int> mpp;
    int count = 0;
    int n = nums.size();
    int xor_res = 0;
    mpp[0] = 1;
    for(int i = 0;i<n;i++){
        xor_res = nums[i] ^ xor_res;
        int target = xor_res ^ k; 
        if(mpp.find(target) != mpp.end())
            count += mpp[target];
        mpp[xor_res]++;
    }
    return count;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    int m = intervals.size();  
    if(m == 0)
        return {};     
    sort(intervals.begin(),intervals.end());
    result.push_back(intervals[0]);
    int r = 0;
    for(int i=1;i<m;i++){
        if(result[r][1] >= intervals[i][0])
            result[r][1] = std::max(result[r][1],intervals[i][1]);
        else{
            result.push_back(intervals[i]);
            r++;
        }
    }
    return result;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int n1 = m-1;
    int n2 = n-1;
    int cur = m+n-1;
    while(n1 >= 0 && n2 >= 0){
        if(nums2[n2] > nums1[n1])
            nums1[cur--] = nums2[n2--];
        else
            nums1[cur--] = nums1[n1--];
    }
    while(n2 >=0){
        nums1[cur--] = nums2[n2--];
    }
}

vector<ll> findMissingAndRepeating(vector<int>& nums){
    int n = nums.size();
    ll sn = n*(n+1)/2 ,sn_squared = n*(n+1)*(2*n+1)/6;
    ll s = 0, s_squared = 0;
    // x is repeating, y is missing
    ll x,y;

    for(int i=0;i<n;i++){
        s += nums[i];
        s_squared +=  ll(nums[i]) * ll(nums[i]);
    }
    // sn = s - x + y => x-y = s - sn => x = s - sn + y
    // sn_squared = s_squared - (x*x - y*y)
    // sn_squared = s_squared - (x-y)(x+y)
    // sn_squared = s_squared - (s - sn)(x+y)
    // sn_squared = s_squared - (s - sn)(s - sn + y + y)
    // y = (((s_squared - sn_squared) / (s - sn) ) - s + sn) / 2
    // x = s - sn + y

    y = (((s_squared - sn_squared)/(s-sn)) - s+sn)/2;
    x = s - sn + y;

    return {x,y};
}

vector<ll> findMissingAndRepeatingXOR(vector<int>& nums){
    int xor_res = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        xor_res = xor_res ^ nums[i];
        xor_res = xor_res ^ (i+1);
    }
    int bitNo = 0;
    while(1){
        if(xor_res & 1<<bitNo){
            break;
        }
        bitNo++;
    }
    int zero=0,one=0;
    for(int i=0;i<n;i++){
        if(nums[i] & 1<<bitNo){
            one = one ^ nums[i];
        }else{
            zero = zero ^ nums[i];
        }
        if((i+1) & 1<<bitNo)
            one = one ^ (i+1);
        else
            zero = zero ^(i+1);
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == zero)
            count++;
    }
    if(count == 2)
        return {zero,one};
    else
        return {one,zero};
}

int Merge(vector<int>&nums, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    int count = 0;
    vector<int> temp;

    while(left <= mid && right <= high){
        if(nums[left] > nums[right]){
            temp.push_back(nums[right]);
            count += (mid - left + 1);
            right++;
        }else{
            temp.push_back(nums[left]);
            left++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low ;i<=high;i++){
        nums[i] = temp[i-low];
    }
    return count;
}

int MergeSort(vector<int>& nums, int low, int high){
    int count = 0;
    if(low >= high)
        return 0;

    int mid = (low + high)/2;
    count += MergeSort(nums,low, mid);
    count += MergeSort(nums,mid+1,high);
 

    count += Merge(nums,low,mid,high);
    return count;
}

int countInversions(vector<int>& nums, int n){
    return MergeSort(nums,0,n-1);
}

int CountPair(vector<int>&nums, int low, int mid, int high){
    int count =0;
    int right = mid+1;
    for(int i=low ; i <= mid;i++){
        while(right <= high && nums[i] > 2 * nums[right])
            right++;
        count += (right - (mid + 1));
    }
    return count;
}

int MergeReversePairs(vector<int>&nums, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    int count = 0;
    vector<int> temp;
    count += CountPair(nums, low, mid ,high);

    while(left <= mid && right <= high){
        if(nums[left] > nums[right]){
            temp.push_back(nums[right]);
            right++;
        }else{
            temp.push_back(nums[left]);
            left++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low ;i<=high;i++){
        nums[i] = temp[i-low];
    }
    return count;
}

int RMergeSort(vector<int>& nums, int low, int high){
    int count = 0;
    if(low >= high)
        return 0;

    int mid = (low + high)/2;
    count += RMergeSort(nums,low, mid);
    count += RMergeSort(nums,mid+1,high);
 

    count += MergeReversePairs(nums,low,mid,high);
    return count;
}

int countReversePairs(vector<int>& nums, int n){
    return RMergeSort(nums,0,n-1);
}

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pref = 1, suff = 1;
    int max_prod = INT_MIN;
    for(int i=0;i<n;i++){
        if(pref == 0)
            pref = 1;
        if(suff == 0)
            suff = 1;
        pref *= nums[i];
        suff *= nums[n-i-1];
        max_prod = std::max(max_prod, std::max(suff, pref));
    }
    return max_prod;
}

int main(){
    vector<int> test1 = {-5, -2, 4, 5, 0, 0, 0};
    vector<int> test2 = {1,3,2,3,1};
    cout<<countReversePairs(test2, 5);
    for(auto i:test2){
        cout<<i<<" ";
    }
}   