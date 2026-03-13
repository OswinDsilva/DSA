#include<bits/stdc++.h>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

typedef long long int lli;

void SelectionSort(vector<int>& v){
    int min_idx,temp;
    int n = v.size();
    for(int i=0;i<n-1;i++){
        min_idx = i;
        for(int j=i+1;j<n;j++)
            if(v[j] < v[min_idx])
                min_idx = j;
        temp = v[min_idx];
        v[min_idx] = v[i];
        v[i] = temp;      
    }
}
void BubbleSort(vector<int>& v){
    int n = v.size();
    int temp;
    bool swap;
    for(int i=0;i<n-1;i++){
        swap = false;
        for(int j=0;j<n-i-1;j++)
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                swap = true;
            }
        if(!swap)
            break;
    }
}
void InsertionSort(vector<int>& v){
    int n = v.size();
    int key;
    for(int i=1;i<n;i++){
        key = v[i];
        int j=i-1;
        for(;j>=0;j--){
            if(v[j] > key)
                v[j+1] = v[j];
            else
                break;
        }
        v[j+1] = key; 
    }
}
void RecursiveBubble(vector<int>& v,int n){
    if(n == 1)
        return;
    for(int j=0;j<n-1;j++){
        if(v[j] > v[j+1])
            std::swap(v[j],v[j+1]);
    }
    RecursiveBubble(v,n-1);
}
void RecursiveInsertion(vector<int>& v,int n,int i=1){
    if(i == n)
        return;
    int j;
    int key = v[i];
    for(j=i-1;j>=0;j--)
        if(v[j] > key)
            v[j+1] = v[j];
        else
            break;
    v[j+1] = key;
    RecursiveInsertion(v,n,i+1);
}

void Merge(vector<int>& v,int low,int mid,int high){
    int left = low,right = mid+1;
    vector<int> aux;
    while(left <= mid && right <= high){
        if(v[left] <= v[right]){
            aux.push_back(v[left]);
            left++;
        }
        else{
            aux.push_back(v[right]);
            right++;
        }
    }
    while(left <= mid){
        aux.push_back(v[left]);
        left++;
    }
    while(right <= high){
        aux.push_back(v[right]);
        right++;
    }
    std::copy(aux.begin(),aux.end(),v.begin()+low);
}
void MergeSort(vector<int>& v,int low,int high){
    if(low == high){
        return;
    }
    int mid = (low+high)/2;
    MergeSort(v,low,mid);
    MergeSort(v,mid+1,high);

    Merge(v,low,mid,high);

} 

int Pivot(vector<int>& v,int start,int end){
    int i=start,j=end;
    int pivot = v[start]; 
    while(i < j){
        while(v[i] <= pivot && i < end)
            i++;
        while(v[j] > pivot && j > start)
            j--;
        if(i < j){
            std::swap(v[j],v[i]);
        }
    }
    std::swap(v[j],v[start]);
    return j;
}
void QuickSort(vector<int>& v,int start,int end){
    if(end <= start)
        return;
    int pivot = Pivot(v,start,end);
    QuickSort(v,start,pivot-1);
    QuickSort(v,pivot+1,end);
}

int main(){
    vector<int> v ={51,32,5,31,46};
    //vector<int> v={5,4,3,2,1};
    QuickSort(v,0,v.size()-1);
    for(auto i:v)
        cout<<i<<endl;
}

