#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};

void insertStart(Node* &head,int value){
    Node *n= new Node(value);

    if(head==NULL){
        head=n;
    }else{
        n->next=head;
        head=n;
    }
}

void insertEnd(Node* &head,int value){
    Node *n= new Node(value);
    if(head==NULL){
        head=n;
    }else{
        Node *temp= head;
        while(temp->next!=NULL){
           temp=temp->next;
        }
        temp->next=n;
    }
}

void printList(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Reverse The link list
void reverseList(Node* &head){
    Node *pre=NULL;
    Node *curr=head;
    Node *remain=NULL;

    while(curr!=NULL){
        remain=curr->next;
        curr->next=pre;
        pre=curr;
        curr=remain;
    }
    head=pre;
}

int main(){
    Node *head=NULL;
    insertStart(head,10);
    insertStart(head,20);
    insertEnd(head,40);
    printList(head);
    reverseList(head);
    cout<<endl<<"After reverse list"<<endl;
    printList(head);
}