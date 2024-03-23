#ifndef STUDENT_HEADER_
#define STUDENT_HEADER_
#include <iostream>

using namespace std;

class Student
{
    private:
    int const rollNumber;
    string name;
    string gender;
     static int generatedRollNumber;
     int *marks;

     public:
     Student();
     Student(string name, string gender);
     ~Student();
     void printRecord();
     
     int getRollNumber();

     string getName();

     string getGender();

     int *getMarks();

     void setName(string name);

     void setGender(string gender);

     void setMarks(int marks,int i);
};


#endif