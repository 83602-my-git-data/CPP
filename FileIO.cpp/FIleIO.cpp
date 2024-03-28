#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class Employee
{
private:
    int empid;
    string name;
    double salary;

public:
    Employee()
    {
    }
    Employee(int empid, string name, double salary)
    {
        this->empid = empid;
        this->name = name;
        this->salary = salary;
    }
    void accept()
    {
        cout << "Enter empid - ";
        cin >> empid;
        cout << "Enter name - ";
        cin >> name;
        cout << "Enter salary - ";
        cin >> salary;
    }
    void display()
    {
        cout << "Empid - " << empid << endl;
        cout << "Name - " << name << endl;
        cout << "Salary - " << salary << endl;
        cout << "********************" << endl;
    }
    int getEmpid()
    {
        return empid;
    }
    string getName()
    {
        return name;
    }
    double getSalary()
    {
        return salary;
    }
};

class Student
{
private:
    int rollno;
    string name;
    double percent;

public:
    Student()
    {
    }
    Student(int rollno, string name, double percent)
    {
        this->rollno = rollno;
        this->name = name;
        this->percent = percent;
    }
    void accept()
    {
        cout << "Enter rollno - ";
        cin >> rollno;
        cout << "Enter name - ";
        cin >> name;
        cout << "Enter percent - ";
        cin >> percent;
    }
    void display()
    {
        cout << "Rollno - " << rollno << endl;
        cout << "Name - " << name << endl;
        cout << "Percent - " << percent << endl;
        cout << "********************" << endl;
    }
    int getRollno()
    {
        return rollno;
    }
    string getName()
    {
        return name;
    }
    double getPercent()
    {
        return percent;
    }
};

int menu()
{
    int choice;
    cout << "1. Add Employee" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Display All Employee" << endl;
    cout << "4. Display All Students" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    return choice;
}
void saveEmployees(vector<Student *> &students)
{
    ofstream outfile;
    outfile.open("student.txt");
    for (int i = 0; i < students.size(); i++)
    {
        outfile << students[i]->getRollno() << " " << students[i]->getName() << " " << students[i]->getPercent() << endl;
    }
    outfile.close();
    cout << "*******************************" << endl;
    cout << "All Student are saved in file" << endl;
    cout << "*******************************" << endl;
}
void saveEmployees(vector<Employee *> &empList)
{
    ofstream fout("employee.txt");
    for (int i = 0; i < empList.size(); i++)
    {
        fout << empList[i]->getEmpid() << ",";
        fout << empList[i]->getName() << ",";
        fout << empList[i]->getSalary() << endl;
    }
    fout.close();
    cout << "*******************************" << endl;
    cout << "All employees are saved in file" << endl;
    cout << "*******************************" << endl;
}

void loadStudent(vector<Student *> &studentList){
    ifstream fin("student.txt");
    int rollno;
    string name;
    double percent;
    while (fin >> rollno >> name >> percent)
    {
        Student *temp = new Student(rollno, name, percent);
        studentList.push_back(temp);
    }
    fin.close();
    cout << "*******************************" << endl;
    cout << "All students are loaded from file" << endl;
    cout << "*******************************" << endl;
}

void loadEmployees(vector<Employee *> &empList)
{
    ifstream fin("employee.txt");
    string data;
    while (getline(fin, data))
    {
        stringstream obj(data);
        string empid, name, salary;
        getline(obj, empid, ',');
        getline(obj, name, ',');
        getline(obj, salary, ',');
        empList.push_back(new Employee(stoi(empid), name, stod(salary)));
    }
    fin.close();
    cout << "*******************************" << endl;
    cout << "All employees are loaded from file" << endl;
    cout << "*******************************" << endl;
}

int main()
{
    vector<Employee *> empList;
    vector<Student *> studentList;
    loadEmployees(empList);
    // call the loadstudents() here;
    loadStudent(studentList);
    int choice;
    int id;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            Employee *eptr = new Employee();
            eptr->accept();
            empList.push_back(eptr);
        }
        break;
        case 2:
            {// to do-> student accept
            // push the student in studentList vector
            // refere case 1}
            Student *student = new Student();
            student->accept();
            studentList.push_back(student);
            }
            break;
        case 3:
        {
            for (int i = 0; i < empList.size(); i++)
                empList[i]->display();
        }       
            break;
        case 4:
        {
            for (int i = 0; i < studentList.size(); i++)
                studentList[i]->display();
        }        
            break;
        default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }

    saveEmployees(empList);
    // call the savestudents() here;
    saveEmployees(studentList);

    cout << "Thank you for using our app.." << endl;
    return 0;
}