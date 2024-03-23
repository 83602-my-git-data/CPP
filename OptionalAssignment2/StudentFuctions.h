#ifndef STUDENT_FUNCTIONS
#define STUDENT_FUNCTIONS
#include "Student.h"

class StudentFunctions
{
 
  private:
    Student **student; // Student student 
    int index=0;
    int size;

    void acceptMarks();
       
  public:
    StudentFunctions();

    StudentFunctions(int size);
    
    ~StudentFunctions();

    void addStudent(string name, string gender);

    void displayStudent();

    void searchRecords(int rollNo);

    void sortRecords();
};

#endif