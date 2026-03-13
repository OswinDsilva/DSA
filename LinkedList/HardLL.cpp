#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *next;
    TreeNode *child;
    TreeNode():val(0),next(nullptr),child(nullptr);
};

ListNode* reverseList(ListNode *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *prev = nullptr,*curr = head,*next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode* findKNodes(ListNode *head,int k){
    k--;
    ListNode *temp = head;
    while(temp != nullptr && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}
ListNode* ReverseKGroup(ListNode *head,int k){
    if(head == nullptr || head->next == nullptr)
        return head;

    if(k == 1)
        return head;
    
    ListNode *start = head;
    ListNode *kth = nullptr;
    ListNode *last = nullptr;
    while(start != nullptr){
        kth = findKNodes(start,k);
        if(kth == nullptr){
            if(last != nullptr)
                last->next = start;
            break;
        }
        ListNode *next = kth->next;
        kth->next = nullptr;
        kth = reverseList(start);
        if(start == head)
            head = kth;
        else
            last->next = kth;
        last = start;
        start = next;
    }
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr)
        return head;
    int len = 1;
    ListNode *temp = head;
    while(temp->next != nullptr){
        len++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % len;
    int count = len - k ;
    while(count--)
        temp = temp->next;
    head = temp->next;
    temp->next = nullptr;
    return head;
}

TreeNode* MergeLists(TreeNode* l1,TreeNode* l2){
    if(l2 == nullptr)
        return l1;
    if(l1 == nullptr)
        return l2;
    TreeNode temp;
    TreeNode *itr = &temp;
    itr->next = nullptr;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val > l2->val){
            itr->child = l2;
            l2 = l2->child;
        }else{
            itr->child = l1;
            l1 = l1->child;
        }
        itr = itr->child;
    }
    if(l1 != nullptr)
        itr->child = l1;
    else
        itr->child = l2;
    return temp.child;
}
TreeNode* FlattenList(TreeNode* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    TreeNode *l1=head,*l2=head->next;
    l1->next = nullptr;

    l1 = FlattenList(l1);
    l2 = FlattenList(l2);

    return MergeLists(l1,l2);
}

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//hashmap approach
Node* copyRandomList(Node* head) {
    Node dummy(-1);
    Node *temp = &dummy;
    Node *temp2 = head;
    std::unordered_map<Node*,Node*> map;
    while(temp2 != nullptr){
        temp->next = new Node(temp2->val);
        temp = temp->next;
        map[temp2] = temp;
        temp2 = temp2->next;
    }
    temp = head;
    while(temp != nullptr){
        if(temp->next != nullptr)
            map[temp]->next = map[temp->next];
        else
            map[temp]->next = nullptr;
        if(temp->random != nullptr)    
            map[temp]->random = map[temp->random];
        else
            map[temp]->random = nullptr;
        temp = temp->next;
    }

    return dummy.next;
}

//interleaving approach
Node* copyRandomList(Node* head){
    Node *temp = head;
    Node *next = nullptr;
    while(temp != nullptr){
        next = temp->next;
        temp->next = new Node(temp->val);
        temp->next->next = next;
        temp = next;
    }
    temp = head;
    while(temp != nullptr){
        next = temp->next->next;
        if(temp->random != nullptr)
            temp->next->random = temp->random->next;
        else
            temp->next->random = nullptr;
        temp = next;
    }
    Node *newHead = head->next;
    temp = head;
    Node *temp2 = newHead;
    while(temp != nullptr){
        temp->next = temp2->next;
        temp = temp->next;
        temp2->next = temp != nullptr?temp->next:nullptr;
        temp2 = temp2->next;
    }
    return newHead;
}