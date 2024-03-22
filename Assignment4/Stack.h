#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

class Stack
{
    private:
      int size;
      int *stack;
      int top=-1;
      
    public:
      Stack();
      Stack(int size);
      ~Stack();
      void print();
      void push(int num);

      int pop();
      int peek();
      bool isEmpty();
      bool isFull();
};

#endif