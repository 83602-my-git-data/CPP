#include "StudentFuctions.h"

void StudentFunctions::acceptMarks(){
        for(int i=0; i<3;i++){
          int marks;
          cout<<"Enter The Marks of "<< i+1 <<" Subjects :: "<<endl;
          cin>>marks;
          student[index]->setMarks(marks,i);
        }
       }

StudentFunctions::StudentFunctions():StudentFunctions(5){
     };

StudentFunctions::StudentFunctions(int size){
       this->size=size;
       student = new Student* [size]; // student = new Student[size];
     };

StudentFunctions::~StudentFunctions(){
      for(int i=0; i<index;i++){
        delete student[i];
        student[i]= NULL;
      }
       delete[] student;
       student=NULL;
     };

void StudentFunctions::addStudent(string name, string gender){
      if(index<size){
      
        student[index] = new Student(name,gender);
        cout<<"Marks Enter ::"<<endl;
         acceptMarks();
       index++;
      }
      else
        cout<<"Size of "<<size<<" student array is fulled."<<endl;
     };

void StudentFunctions::displayStudent(){
       for(int i=0;i<index;i++)
         student[i]->printRecord();
         cout<<endl;
     };

void StudentFunctions::searchRecords(int rollNo){
        for(int i=0; i<index;i++){
            if(student[i]->getRollNumber()==rollNo){
               cout<<endl;
               student[i]->printRecord();
               cout<<endl; 
              }
              return ; 
        }
        cout<<"Student is not Found!!!"<<endl;
              cout<<"Enter valid RollNo!!"<<endl;
              cout<<endl;
     }

void StudentFunctions:: sortRecords(){
       //insertion sort
        for(int i=1; i<index;i++){
             Student *std = student[i];
             int j=i-1;
            for(; j>=0 && student[j]->getRollNumber()<std->getRollNumber();j--){
              student[j+1] = student[j];
            }  
            student[j+1]=std;
        }

        cout<<"Sorted By RollNo is Done!!!"<<endl;
        cout<<endl;
     }
