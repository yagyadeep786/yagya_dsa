#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *pre;
    Node *next;

    Node(int value){
        this->data=value;
        this->pre=NULL;
        this->next=NULL;
    }

    ~Node(){
        int val= this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    }
};

// inster node in start;

void insertStart(Node* &head,int value){
    Node *n= new Node(value);
      
    if(head==NULL){
        head=n;
    }else{
        n->next=head;
        head->pre=n;
        head=n;
    }
}

void insertEnd(Node* &head,int value){
    Node *temp= head;
    Node *n= new Node(value);
    if(temp==NULL){
        temp=n;
    }else{

        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->pre=temp;
    }
}
int lengthOfList(Node* &head){
    int len=0;
    Node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

// inset at middle in the list

void insertPos(Node* &head,int pos,int value){
    if(pos==1){
        insertStart(head,value);
    }
    else if(pos==lengthOfList(head)){
        insertEnd(head,value);
    }
    else{
    Node *n= new Node(value);
    Node *temp=head;
    int count=1;
    while(count<pos){
        count++;
        temp=temp->next;
    }
    n->next= temp->next;
    temp->next->pre=n;
    temp->next=n;
    n->pre=temp;
    }
}

// length of the list

void printList(Node* temp){
    if(temp==NULL){
        cout<<"List is empty";
    }else{
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
  }
}
// Deletion oparation in list

void deleteStart(Node* &head){
    Node *temp= head;
    if(temp==NULL){
        cout<<"List is Empty";
    }else{
        temp->next->pre=NULL;
        temp= temp->next;
        temp->next=NULL;
        delete temp;
    }
}

void deleteEnd(Node* &head){
    Node *temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->pre->next==NULL;
}

void deletePos(Node* &head,int pos){

    if(pos==1){
        deleteStart(head);
    }
    else if(pos==lengthOfList(head)){
        deleteEnd(head);
    }else{
       Node *current=head;
       int count=1;
       while(count<pos){
         current=current->next;
         count++;
       }
        current->pre->next=current->next;
        current->next->pre=current->pre;
    }
}


int main(){
    Node *Head=NULL;
    insertStart(Head,10);
    insertStart(Head,20);
    insertEnd(Head,25);
    insertPos(Head,2,50);
    deletePos(Head,2);
    printList(Head);

   cout<<lengthOfList(Head);
}