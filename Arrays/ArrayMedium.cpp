#include<bits/stdc++.h>

using std::vector;

vector<int> TwoSum(vector<int>& nums,int target){
    std::unordered_map<int,int> hashmap;
    for(int i=0;i<nums.size();i++){
        if(hashmap.find(target-nums[i]) != hashmap.end())
            return{hashmap[target-nums[i]],i};
        hashmap[nums[i]] = i;
    }
    return {};
}

void Sort012(vector<int>& nums){
    int low = 0,high = nums.size()-1,mid = low;
    while(mid <= high){
        if(nums[mid] == 0){
            std::swap(nums[mid],nums[low]);
            low++;
            mid++;
        }else if(nums[mid] == 2){
            std::swap(nums[mid],nums[high]);
            high--;
        }
        else
            mid++;
    }
}

int MajorityElement(vector<int>& nums){
    int element,count = 0;
    for(int i=0;i<nums.size();i++){
        if(count == 0){
            element = nums[i];
            count = 1;            
        }
        else if(nums[i] != element)
            count--;
        else
            count++;
    }
    return element;
}

int maxSubArray(vector<int>& nums) {
    int sum=0,maxSum = INT_MIN;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(sum > maxSum)
            maxSum = sum;
        if(sum < 0)
            sum = 0;
    }
    return maxSum;
}

void PrintMaxSubArray(vector<int>& nums){
    int left=0,right=0,temp=0;
    int sum=0,maxSum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];

        if(sum > maxSum){
            maxSum = sum;
            left = temp;
            right = i;
        }
        if(sum < 0){
            sum = 0;
            temp = i+1;
        }
    }
    for(int i = left;i<=right;i++){
        std::cout<<nums[i]<<"\t";
    }
}

int BuySell(vector<int>& prices){
    int low = prices[0],profit = 0;
    for(int i=1;i<prices.size();i++){
        if(prices[i] < low){
            low = prices[i];
        }else{
            profit = std::max(profit,prices[i] - low);
        }
    }
    return profit;
}

vector<int> rearrangeArray(vector<int>& nums) {
    int i = 0, p = 0, n = 0,nextPos = 0,nextNeg = 0;
    while(nums[p] < 0)
        p++;
    nextPos = nums[p];
    while(nums[n] < 0)
        n++;
    nextNeg = nums[n];
    while(i < nums.size()){        
        if(i%2 == 0){
            if(nums[i] < 0){
                n = nums[i];
                std::swap(p,nums[i]);
            }
        }else{
            return {};
        }
    }
    return nums;
}


vector<int> findLeaders(vector<int>& nums){
    int n = nums.size();
    int max = nums[n-1];
    vector<int> result;
    result.push_back(max);
    for(int i=n-2; i >= 0;i--){
        if (nums[i] > max){
            max = nums[i];
            result.push_back(max);
        }
    }
    for(int i=0;i<result.size();i++){
        std::cout<<result[i]<<std::endl;
    }
    return result;
}

int longestConsecutiveSequence(vector<int>& nums){
    int n = nums.size();
    int count = 0;
    int longest = 0;
    std::unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(nums[i]);
    }
    for(auto i: s){
        if ((s.find(i-1) != s.end()))
            continue;
        count = 1;
        while(s.find(i+count) != s.end())
            count++;
        longest = std::max(longest,count);
    }
    return longest;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;
    int top = 0, bottom = m-1, left = 0, right = n-1;
    while(left <= right && top <= bottom){    
        for(int i = left; i <= right ;i++)
            result.push_back(matrix[top][i]);
        top++;
        for(int i = top; i <= bottom ;i++)
            result.push_back(matrix[i][right]);
        right--;
        if(top <= bottom){
            for(int i = right ; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top ;i--)
                result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}

vector<int> setZeroes(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int first_row = 1;
    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            if(matrix[row][col] == 0){
                if(row == 0)
                    first_row = 0;
                else
                    matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }
    for(int row=1;row<m;row++){
        for(int col=1;col<n;col++){
            if(matrix[0][col] == 0 || matrix[row][0] == 0)
                matrix[row][col] = 0;
        }
    }

    if(matrix[0][0] == 0)
        for(int row=0;row<m;row++)
            matrix[row][0] = 0;
    if(first_row == 0)
        for(int col=0;col<n;col++)
            matrix[0][col] = 0;
}

// Adding the previous row 2 elements , DP method
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    for(int i=0;i<numRows;i++){
        for(int j=0;j<=i;j++){
            if(j == 0)
                result[i].push_back(1);
            else if(j == i)
                result[i].push_back(1);
            else
                result[i].push_back(result[i-1][j] + result[i-1][j-1]);
        }
    }
    return result;
}


vector<int> NcR_Row(int N){
    vector<int> result;
    int ans = 1;
    result.push_back(ans);
    for(int i = 1;i<N;i++){
        ans *= (N-i);
        ans /= (i);
        result.push_back(ans);
    }
    return result;
}
vector<vector<int>> generate2(int numRows){
    vector<vector<int>> result;
    for(int i=1;i<=numRows;i++){
        vector<int> ans = NcR_Row(i);
        result.push_back(ans);
    }
    return result;
}

int main(){
    vector<vector<int>> test = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> result = generate2(5);
    for(auto i:result){
        for(auto j:i){
            std::cout<<j<<" ";
        }
        std::cout<<"\n";
    }
}