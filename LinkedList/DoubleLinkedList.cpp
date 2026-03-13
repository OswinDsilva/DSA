#include<bits/stdc++.h>

typedef struct DNode Node; 

struct DNode{
    int data;
    Node* next;
    Node* prev;
    DNode(int x): data(x),next(nullptr),prev(nullptr) {}
};

Node* CreateNode(int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    return newNode;
}

Node* InsertNodeAtEnd(Node *head,int val){
    Node *newNode = CreateNode(val);
    Node *temp = head;
    if(head == nullptr)
        return newNode;
    while(temp->next != nullptr)
        temp = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    return head;
}

Node* DeleteEndNode(Node *head){
    if(head == nullptr)
        return head;
    if(head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->prev->next = nullptr;
    free(temp);
    return head;
}

Node* Reverse(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node *temp = head,*temp2=nullptr;
    while(temp != nullptr){
        temp2 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp=temp->prev;
    }
    return temp2->prev;
}


// n<-1<=>2<=>3<=>4->n
int main(){

}