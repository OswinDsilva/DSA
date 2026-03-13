#include<bits/stdc++.h>


struct ListNode{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x):val(x),next(nullptr),prev(nullptr) {};
    ListNode(int x,ListNode *next):val(x),next(next),prev(nullptr) {};
    ListNode(int x,ListNode *next,ListNode *prev):val(x),next(next),prev(prev) {};
};

ListNode* DeleteOccurences(ListNode* head,int key){
    ListNode *del = nullptr;
    while(head != nullptr && head->val == key ){
        del = head;
        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        delete del;
    }
    ListNode *temp = head;
    while(temp != nullptr){
        del = nullptr;
        if(temp->val == key){
            temp->prev->next = temp->next;
            if(temp->next != nullptr){
                temp->next->prev = temp->prev;
            }
            del = temp;
        }
        
        temp = temp->next;
        if(del) delete del;
    }
    return head;
}

void PairSum(ListNode* head,int sum){
    if(head == nullptr || head->next == nullptr)
        return ;
    std::unordered_map<int,int> hashmap;
    ListNode* temp = head;
    int i=0;
    while(temp != nullptr){
        i++;
        if(hashmap.find(sum - temp->val) != hashmap.end()){
            std::cout<<"{"<<sum-temp->val<<","<<temp->val<<"}"<<std::endl;
        }
        if(hashmap.find(temp->val) == hashmap.end())
            hashmap[temp->val] = i;
        temp = temp->next;
    }
}

void SortedPairSum(ListNode* head,int sum){
    if(head == nullptr || head->next == nullptr)
        return ;
    
    ListNode* temp = head;
    ListNode* tail = head;
    while(tail->next != nullptr)
        tail = tail->next;
    while(temp != tail && temp->prev != tail){
        if(temp->val + tail->val == sum){
            std::cout<<temp->val<<","<<tail->val<<std::endl;
            temp = temp->next;
            tail = tail->prev;
        }else if(temp->val + tail->val > sum){
            tail = tail->prev;
            continue;
        }
        else{
            temp = temp->next;
            continue;
        }  
    }
}

ListNode* RemoveDuplicates(ListNode* head){
    if(head == nullptr)
        return head;
    ListNode *temp = head->next, *curr = head,*del;
    while(temp != nullptr){
        if(temp->val != curr->val){
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
            temp = temp->next;
        }
        else{
            del = temp;
            temp = temp->next;
            delete del;
        }  
    }
    curr->next = nullptr;
    return head;
}