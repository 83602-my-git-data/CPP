#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <class T>
class Stack
{
    private:
      int size;
      T *stack;
      int top=-1;
      
    public:
      Stack();
      Stack(int size);
      ~Stack();
      void print();
      void push(T num);

      T pop();
      T peek();
      bool isEmpty();
      bool isFull();
};

#endif