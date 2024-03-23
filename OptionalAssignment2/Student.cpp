#include "Student.h"


Student::Student(string name, string gender):rollNumber(++generatedRollNumber)
     {
         this->name = name;
         this->gender = gender;
         marks = new int[3];

     }

Student::~Student()
     {   delete [] marks;
         marks = NULL;
     }

void Student::printRecord()
     {  
        int totalMarks=0;
         cout << "Roll Number: " << rollNumber << endl;
         cout << "Name: " << name << endl;
         cout << "Gender: " << gender << endl;
         for(int i=0; i<3;i++){
             cout << "Subject Marks " << i+1 << ": " << marks[i] << endl;
             totalMarks += marks[i];
         }
         cout << "Total Marks: " << totalMarks << " And Percentage ::" << totalMarks/3 << "%" << endl;
     }
     
int Student::getRollNumber()
     {
         return rollNumber;
     }

string Student::getName()
     {
         return name;
     }
string Student:: getGender()
     {
         return gender;
     }

int *Student::getMarks(){
         return marks;
     }

void Student::setName(string name)
     {
         this->name = name;
     }

void Student::setGender(string gender)
     {
         this->gender = gender;
     }

void Student::setMarks(int marks,int i)
     {
         this->marks[i] = marks;
     }

int Student::generatedRollNumber = 1000;
