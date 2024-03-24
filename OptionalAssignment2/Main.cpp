#include "StudentFuctions.h"

int main(){
    StudentFunctions *std = new StudentFunctions();
    string name;
    string gender;
    int size;
    int choice=0; 
     do
    {   cout<<endl;
        cout << "0. EXIT" << endl;
        cout << "1. Size Of Student in Class." << endl;
        cout << "2. Add Students." << endl;
        cout << "3. Display Student." << endl;
        cout << "4. Search By RollNo." << endl;
        cout<<  "5. Descending Sorting By RollNo." << endl;
        cout << "6. Get Marks Of particular Student." << endl;
        cout << "7. " << endl;
        cout << "Enter choice - "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            delete std;
             std=NULL;
            cout << "Thank you" << endl;
            break;
        case 1:
            cout<<"Enter the SIZE ::"<<endl;
            cin>>size;
            std = new StudentFunctions(size);
            break;
        case 2:
              cout<<"Enter Your Name >"<<endl;
              getchar();
              getline(cin,name);
              cout<<"Enter Your Gender"<<endl;
              cin>>gender;
             std->addStudent(name,gender);
            break;
        case 3:
            std->displayStudent();
            break;
        case 4:
               int rollno;
               cout<<"Enter the RollNo"<<endl;
               cin>>rollno;
                std->searchRecords(rollno);
            break;
        case 5:
             std->sortRecords();
             break;
        case 6:
            cout << "Enter the Roll No Of Students ::" << endl;
            {
                int rollno;
                cin >> rollno;
                std->findMarks(rollno);
            }
           break; 
        case 7:
             cout << "Wrong choice..." << endl;
            break;        
        default:
            cout << "Wrong choice..." << endl;
            break;
        }   
     }while(choice!=0);
    
     return 0;
};