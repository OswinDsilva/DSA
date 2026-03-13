#include<bits/stdc++.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

ListNode* middleNode(ListNode* head){
    ListNode *fast = head,*slow = head;
    if(head->next == nullptr)
        return head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* Reverse(ListNode* head){
    ListNode *temp=head,*prev=nullptr,*next=nullptr;
    if(head == nullptr || head->next == nullptr)
        return head;
    while(temp != nullptr){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

ListNode* RecursReverse(ListNode* head,ListNode *prev=nullptr){
    if(head == nullptr){
        return prev;
    }
    ListNode* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    return RecursReverse(head,prev);
}

ListNode* RecursReverse2(ListNode* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode* newHead = RecursReverse2(head->next);
    ListNode* temp = head->next;
    temp->next = head;
    head->next = nullptr;
    return newHead;
}

bool DetectCycle(ListNode* head){
    ListNode *fast=head,*slow=head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

ListNode* FindCycleStart(ListNode *head){
    ListNode *fast=head,*slow=head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            slow = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return 0;
}

int FindCycleLength(ListNode *head){
    ListNode *fast=head,*slow=head;
    int len = 1;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            slow = slow->next;
            while(fast != slow){
                len++;
                slow = slow->next;    
            }
            return len;
        }
    }
    return 0;
}

ListNode* ReverseFrom(ListNode *node){
    ListNode *prev=nullptr,*next=nullptr;
    while(node != nullptr){
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}
bool Palindrome(ListNode *head){
    ListNode *fast = head,*slow = head;
    ListNode *mid;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;
    
    mid->next = ReverseFrom(slow->next);

    slow = head;
    fast = mid->next;
    while(fast != nullptr){
        if(slow->val != fast->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

ListNode* EvenOddList(ListNode *head){
    ListNode *even,*odd=head,*EvenStart;
    if(head == nullptr)
        return head;
    even = head->next;
    EvenStart = even;
    while(even != nullptr && even->next != nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = EvenStart;
    return head;
}

ListNode* DeleteNthFromEnd(ListNode* head,int k){
    ListNode *fast=head,*slow=head;
    while(k--)
        fast = fast->next;
    if(fast == nullptr)
        return head->next;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

ListNode* DeleteMiddle(ListNode* head){
    ListNode *fast=head,*slow=head;
    if(head->next == nullptr)
        return nullptr;
    fast = fast->next;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}


ListNode* FindMiddle(ListNode* head){
    ListNode *slow=head,*fast=head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* Merge(ListNode *left, ListNode *right){
    ListNode *temp = new ListNode(0);
    ListNode *head = temp;

    while(left != nullptr && right != nullptr){
        if(right->val > left->val){    
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    while(left != nullptr){
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while(right != nullptr){
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    
    temp = head->next;
    delete head;
    return temp;
}
ListNode* MergeSort(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
        
    ListNode *left = head;
    ListNode *mid = FindMiddle(head);
    ListNode *right = mid->next;
    mid->next = nullptr;

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left,right);
}

ListNode* Sort012(ListNode* head){
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode* temp = head;
    int hashmap[3]={0};
    while(temp != nullptr){
        hashmap[temp->val]++;
        temp = temp->next;
    }
    temp = head;    
    for(int i=0;i<3;i++){
        while(hashmap[i] != 0){
            temp->val = i;
            temp = temp->next;
            hashmap[i]--;
        }
    }
    return head;
}

ListNode* Sort012Pointers(ListNode* head){
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode p0Head(0),p1Head(1),p2Head(2);
    ListNode *p0 = &p0Head,*p1 = &p1Head,*p2 = &p2Head;
    ListNode *temp = head;
    while(temp != nullptr){
        if(temp->val == 0){
            p0->next = temp;
            p0 = p0->next;
        }
        if(temp->val == 1){
            p1->next = temp;
            p1 = p1->next;
        }
        if(temp->val == 2){
            p2->next = temp;
            p2 = p2->next;
        }
        temp = temp->next;
    }
    p2->next = nullptr;
    if(p0Head.next == nullptr && p1Head.next == nullptr)
        return p2Head.next;
    if(p0Head.next == nullptr){
        p1->next = p2Head.next;
        return p1Head.next;
    }
    if(p1Head.next == nullptr){
        p0->next = p2Head.next;
        return p0Head.next;
    }
    p0->next = p1Head.next;
    p1->next = p2Head.next;
    return p0Head.next;
}

int Intersection(ListNode *head1,ListNode *head2){
    ListNode *temp1 = head1,*temp2 = head2;
    int l1=0,l2=0;
    while(temp1 != nullptr){
        l1++;
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        l2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    while(temp1 != nullptr && temp2 != nullptr){
        while(l1 > l2){
            temp1 = temp1->next;
            l1--;
        }
        while(l2 > l1){
            temp2 = temp2->next;
            l2--;
        }
        if(temp1 == temp2)
            return temp1->val;
        temp1 = temp1->next;
        l1--;
        temp2 = temp2->next;
        l2--;
    }
    return 0;
}


ListNode* OneAddition(ListNode *head){
    if(head == nullptr)
        return head;
    head = Reverse(head);
    int carry = 1;
    ListNode *temp = head;
    while(temp != nullptr && carry > 0){
        temp->val += carry;
        carry = temp->val / 10;
        temp->val %= 10;
        if(temp->next == nullptr && carry > 0){
            temp->next = new ListNode(carry);
            break;
        }
        temp = temp->next;
    }
    head = Reverse(head);
    return head;
}

int FindCarry(ListNode *head){
    if(head == nullptr)
        return 1;

    int carry = FindCarry(head->next);
    head->val += carry;
    if(head->val == 10){
        head->val = 0;
        return 1;
    }
    return 0;
}
ListNode *OneAdditionRecursion(ListNode *head){
    if(head == nullptr)
        return head;
    int carry = FindCarry(head);
    if(carry == 1){
        ListNode *newNode = new ListNode(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

ListNode *AddTwo(ListNode *l1,ListNode *l2){
    int carry = 0,sum;
    ListNode result(-1);
    ListNode *temp = &result;
    ListNode *p1 = l1,*p2= l2;

    while(p1 != nullptr || p2 != nullptr || carry){
        sum = carry;
        if(p1 != nullptr){
            sum += p1->val;
            p1 = p1->next;
        }
        if(p2 != nullptr){
            sum += p2->val;
            p2 = p2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        temp->next = new ListNode(sum);
        temp = temp->next;
        
    }
    return result.next;
}