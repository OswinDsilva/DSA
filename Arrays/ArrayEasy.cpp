#include<bits/stdc++.h>
using namespace std;
int LargestEle(int arr[],int n){
    if(n == 0){
        return -1;
    }
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

int SecondLargestEle(int arr[],int n){
    int max=INT_MIN,smax=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            smax = max;
            max = arr[i];
            continue;
        }
        if(arr[i] > smax){
            smax = arr[i];
            continue;
        }
    }
    if(smax == INT_MIN){
        return -1;
    }
    return smax;
}

bool CheckSorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int RemoveDuplicate(int arr[],int n){
    int curr=0;
    for(int i=1;i<n;i++){
        if(arr[curr] != arr[i]){
            curr++;
            arr[curr] = arr[i];
        }
    }
    return curr+1;
}

int MinIdx(std::vector<int>& nums){
    int min = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[min] > nums[i])
            min = i;
    }
    return min;
}
bool CheckRotSorted(std::vector<int>& nums) {
    int i = MinIdx(nums)+1;
    int prev;
    std::cout<<i<<"<-";
    int n = nums.size();
    while(--n){
        prev = i-1;
        std::cout<<"prev="<<prev<<"\t"<<"i="<<i<<std::endl;
        if(i == nums.size()){
            i = 0;
        }
        if(nums[prev] > nums[i])
            return false;
        i++;
    }
    return true;
}

void Rotate(std::vector<int>& nums,int k){
    int n = nums.size();
    k = k % n;
    std::reverse(nums.begin(),nums.end());
    std::reverse(nums.begin(),nums.begin()+k);
    std::reverse(nums.begin()+k,nums.end());
}

void MoveZeroes(std::vector<int>& nums){
    int j = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != 0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}

int LinearSearch(vector<int>& nums,int key){
    for(int i=0;i<nums.size();i++){
        if(nums[i] == key)
            return i;
    }
    return -1;
}

void Union(vector<int> v1,vector<int> v2,vector<int>& v3){
    vector<int>::iterator i=v1.begin(),j=v2.begin();
    while(i != v1.end() && j != v2.end()){
        if(*i == *j){
            if(v3.empty() || v3.back() != *i)    
                v3.push_back(*i);
            ++i;
            ++j;
            continue;
        }
        if(*i > *j){
            if(v3.empty() || v3.back() != *j) 
                v3.push_back(*j);
            ++j;
        }
        else{
            if(v3.empty() || v3.back() != *i) 
                v3.push_back(*i);
            ++i;
        }
    }
    while(i != v1.end()){
        if(v3.empty() || v3.back() != *i) 
            v3.push_back(*i);
        ++i;
    }
    while(j != v2.end()){
        if(v3.empty() || v3.back() != *j) 
            v3.push_back(*j);
        ++j;
    }
}

int FindMissing(vector<int>& nums,int n){
    int sum = 0;
    for(int i=0;i<n-1;i++)
        sum += nums[i];
    return (n*(n+1)/2) - sum;
}

int MaxOnes(vector<int>& nums){
    int maxlength=0,count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 1)
            count++;
        else{
            maxlength = max(maxlength,count);
            count = 0;
        }
    }
    return max(maxlength,count);
}

int SingleNumber(vector<int>& nums){
    int op=nums[0];
    for(int i=1;i < nums.size();i++){
        op ^= nums[i];
    }
    return op;
}

int SumK(vector<int>& nums,int k){
    int left=0,right=0,n=nums.size(),sum=0,maxlen=0;
    while(right < n){
        sum += nums[right];
        while(sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k)
            maxlen = max(right-left+1,maxlen);
        right++;
    }
    return maxlen;
}

int NegativeSumK(vector<int>& nums,int k){
    unordered_map<int,int>hashmap;
    int sum = 0,len=0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(hashmap.find(sum) == hashmap.end()){
            hashmap[sum] = i;
        }
        if(sum == k){
            len = i + 1;
        }
        if(hashmap.find(sum-k) != hashmap.end()){
            len = max(len,i-hashmap[sum-k]);
        }
    }
    return len;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7},n=7;
    std::vector<int> nums = {2,0,0,3};
    vector<int>nums1 ={1,2,3,4,5};
    vector<int> result;
    std::cout<<NegativeSumK(nums,3);
    //MoveZeroes(nums);
    //Union(nums,nums1,result);
    /*
    for(int i=0;i<result.size();i++){
        std::cout<<result[i]<<"\t";
    }
    */
    return 0;
}
