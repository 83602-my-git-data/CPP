#include "Stack.h"
int main(){
    int choice =0;
    int size;
    int value =0;
     Stack *stack = NULL;
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
              stack = new Stack(size);
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