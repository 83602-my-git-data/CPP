/*Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using 
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not 
given, allocate stack of size 5. 
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().*/

#include "Stack.h"

  Stack::Stack():Stack(5){}
  Stack::Stack(int size){
        stack = new Stack[size];
        this->size = size;
        cout<<"Stack initialized of size "<<size<<endl;  
      }

  Stack::~Stack(){
        delete []stack;
        stack=NULL;
      }
     void Stack::print(){
        if(!isEmpty()){
         for(int i=top;i>=0;i--){
           cout<<stack[i]<<" ";
         }
            cout<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
     }
   void Stack::push(T num)
   {
       if(isFull())
       {
           cout<<"Stack is full"<<endl;
       }
       else
       {   top++;
           stack[top] = num;
       }
   }
   
   T Stack::pop()
   {
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    } 
    
     int val = stack[top];
        top--;
        return val;
   }
   
   T Stack::peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return stack[top];
   }
    bool Stack::isEmpty(){
        if(top==-1)
            return true;

            return false;
      }

    bool Stack::isFull(){
        if(top==size)
            return true;
    
            return false;
      }   
