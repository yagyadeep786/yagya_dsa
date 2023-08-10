#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
   Node(int value){
        this->data= value;
        this->next= NULL;
    }
};

Node *Head=NULL;

void insertEnd(int value){
    Node *n= new Node(value);
    if(Head==NULL){
        Head=n;
    }else{
        Node *temp= Head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}

void insertStart(int value){
    Node *n= new Node(value);
    if(Head==NULL){
        Head=n;
    }else{
       n->next=Head;
       Head=n;
    }
}

void insertPossion(int Possion,int value){
    Node *temp= Head;
    Node *n= new Node(value);
    int count=1;
    while(temp!=NULL){
     temp=temp->next;
     count++;
     if(count==Possion){
        n->next=temp->next;
        temp->next=n;
     }
    }
}
// deleting methods

void deleteStart(){
    if(Head==NULL){
        cout<<"List is empty"<<endl;
    }else{
        Head= Head->next;
    }
}

void deleteEnd(){
    if(Head==NULL){
        cout<<"list is empty"<<endl;
    }else{
        Node *temp=Head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
// please dry run the code
void deletePossion(int Possion){
 
 if(Possion==1){
    Node *temp= Head;
    Head=Head->next;
    
    delete temp;
 }else{
    Node *current= Head;
    Node *previous= NULL;
    
    if(current->next ==NULL){
        deleteEnd();
    }
    int count=2;
    while(count<=Possion){
        previous=current;
        current=current->next;
        count++;
    }
    previous->next=current->next;
    delete current;
 }
}

// print position

void printPos(int pos){
    Node *temp= Head;
   int count=1;
    while(count<pos){
      temp=temp->next;
      count++;
    }
    cout<<count<<"th position value= "<<temp->data<<endl;
    delete temp;
}

void printList(){  
    Node *temp= Head;
    if(Head==NULL){
        cout<<"List is Empty"<<endl;
    }else{
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
  }
}


int main(){
    insertEnd(10);
    insertStart(15);
    insertEnd(20);
    insertPossion(2,100);
    deletePossion(3);
    printList();
    printPos(2);
}