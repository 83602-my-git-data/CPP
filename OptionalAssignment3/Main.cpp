
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
      Stack():Stack(5){}
      Stack(int size){
        stack = new Stack[size];
        this->size = size;
        cout<<"Stack initialized of size "<<size<<endl;  
      }
      ~Stack(){
        delete []stack;
        stack=NULL;
      }
      void print(){
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
      void push(T num){
       if(isFull())
       {
           cout<<"Stack is full"<<endl;
       }
       else
       {   top++;
           stack[top] = num;
       }
   }

      T pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    } 
    
     int val = stack[top];
        top--;
        return val;
   }
      T peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return stack[top];
   }
      bool isEmpty(){
        if(top==-1)
            return true;

            return false;
      }
      bool isFull(){
        if(top==size)
            return true;
    
            return false;
      }
};
int main(){
    int choice =0;
    int size=5;
    int value =0;
     Stack<int> *stack = NULL;
     do
    {
    
        cout << "0. EXIT" << endl;
        cout << "1. Enter the Size of Stack." << endl;
        cout << "2. Enter the value in stack." << endl;
        cout << "3. Display the Stack." << endl;
        cout << "4. Delete the Value in stack." << endl;
        cout<<  "5. Peek Value at Stack." << endl;
        cout << "6. Check Stack is Empty or Not." << endl;
        cout << "7. Check Stack is Full or Not." << endl;
        cout << "Enter choice - "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            delete stack;
            stack = NULL;
            cout << "Thank you" << endl;
            break;
        case 1:
              cout<<"Enter The Size of Stack:: "<<endl;
              cin>>size;
              stack = new Stack<int>(size);
            break;
        case 2:
              cout<<"Enter The Value to be Entered in Stack:: "<<endl;
              cin>>value;
              stack->push(value);
            break;
        case 3:
            cout<<"Stack Value ::"<<endl;
            stack->print();
            break;
        case 4:
               cout<<"The Value to be Deleted in Stack:: "<<stack->pop()<<endl;
            break;
        case 5:
              cout<<"The Value at the Top of Stack:: "<<stack->peek()<<endl;
           break;
        case 6:
              if(stack->isEmpty())
              {
                  cout<<"Stack is Empty"<<endl;
              }
              else
              {
                  cout<<"Stack is Not Empty"<<endl;
              }
           break; 
        case 7:
              if(stack->isFull())
            {
                cout<<"Stack is Full"<<endl;
            }
            else
            {
                cout<<"Stack is Not Full"<<endl;
            }
            break;        
        default:
            cout << "Wrong choice..." << endl;
            break;
        }   
     }while(choice!=0);
     return 0;
};