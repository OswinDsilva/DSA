#include<bits/stdc++.h>

typedef struct Node Node; 

struct Node{
    int data;
    Node* next;
    Node(int x): data(x),next(NULL) {}
};

Node* CreateNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
}

Node* InsertNodeAtBeginning(Node* head,int element){
    Node* newNode = CreateNode(element);
    if(head == NULL)
        return newNode;
    newNode->next = head;
    return newNode;
}

int ListLength(Node *head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

bool FindValue(Node *head,int val){
    Node* temp = head;
    while(temp != NULL && temp->data != val)
        temp = temp->next;
    if(temp == NULL)
        return false;
    return true;
}


int main(){

}