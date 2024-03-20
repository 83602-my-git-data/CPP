/*Q3. Write a menu driven program for Student in CPP language. Create a class student with data 
members roll no, name and marks. Implement the following functions
void initStudent();
void printStudentOnConsole();
void acceptStudentFromConsole();*/

 #include<iostream>
using namespace std;
#include<stdio.h>

class student{
    int rollNo;
    string name;
 double marks;

 public:
 void initStudent(){
 }; 

 void acceptStudentFromConsole(){
     cout<<"Enter roll no: ";
     cin>>rollNo;
     cout<<"Enter name: ";
     cin>>name;
     cout<<"Enter marks: ";
     cin>>marks;
 }

 void printStudentOnConsole(){
    cout<<"Roll No: "<<rollNo<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Marks: "<<marks<<endl;
 }
};

int main(){
    int choice = 0;
    student s;

    do{  cout<<endl;
         cout<<"0.Exits"<<endl;
         cout<<"1.Student Init "<<endl;
         cout<<"2.Student Accept Details"<<endl;
         cout<<"3.Student Details"<<endl;

          cout<<"Enter your choice: ";
          cin>>choice;
          cout<<endl;
          switch(choice){
            case 0 : "Thank You :-)";
               break;

             case 1 : s.initStudent();
                break;
             case 2 : s.acceptStudentFromConsole();
                break;
             case 3 : s.printStudentOnConsole();
                break;
             default: 
                cout<<"Invalid choice!!!!!"<<endl;
                cout<<"Enter again"<<endl;
                break;   
          }
    }while(choice !=0);

    return 0;
}