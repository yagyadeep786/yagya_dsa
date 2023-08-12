#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int value){
       this->data= value;
       this-> next= NULL;
    }

    // ~Node(){
    //     this->next=NULL;
    //     delete this->next;
    // }
};

// Check the stack is full or not
int isEmpty(Node *temp){
    if(temp==NULL){
        return 1;
    }else{
        return 0;
    }
}

// stack element count
int elementCount(Node* &head){
    Node *temp= head;

    int count=0;
    while(temp!=NULL){
        count++;
        temp= temp->next;
    }
    return count;
}
// insert in stack linked list

void insertData(Node* &head,int value){
    Node *n= new Node(value);
    if(isEmpty(head)){
        head=n;
    }else{
       n->next=head;
       head=n;
    }
}

// void delete node from stack linked list

void deleteData(Node* &head){
   if(isEmpty(head)){
    cout<<"Stack is Empty"<<endl;
   }
   else{
    cout<<"Delete element is: "<<head->data<<endl;
    head=head->next;
   }
}

// show stack

void showStack(Node* &head){
    Node *temp=head;
    if(temp==NULL){
        cout<<"Stack is empty";
    }else{
    cout<<"Stack Elements: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    }
}

int main(){
    Node *Head=NULL;
    insertData(Head,5);
    insertData(Head,12);
    insertData(Head,34);
    deleteData(Head);
    cout<<"Stack element count is: "<<elementCount(Head)<<endl;
    showStack(Head);
}
