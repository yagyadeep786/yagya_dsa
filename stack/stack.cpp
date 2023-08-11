

/* 

 Stack: stack is a last in first out linear data structure.


   We can implement stack in two way.
  1. Array 
  2. Linkedlist
*/

#include<iostream>
#define SIZE 5
using namespace std; 


int stack[SIZE];
int top=-1;

// check the stack is empty or not
int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

// check the stack is full or not
int isFull(){
    if(top==SIZE-1){
        return 1;
    }else{
        return 0;
    }
}

// insert data in stack (on top)

void insertData(int value){
    if(isFull()){
        cout<<"Stack is full";
    }else{
        top++;
        stack[top]=value;
    }
}

// delete data from stack (on top)
int deleteData(){
    if(isEmpty()){
        cout<<"Stack is empty";
    }else{
       int a= stack[top];
       top--;
       return a;
    }
}


int main(){
    insertData(5);
    insertData(10);
}
