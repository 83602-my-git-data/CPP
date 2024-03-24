/*Q1. Write a Matrix class. Allocate memory dynamically in parameterized constructor. Also write 
parameter-less constructor. Write accept() and print() functions. 
Also provide add(), subtract(), multiply() and transpose() function.*/

#include <iostream>
using namespace std;

class Matrix{
    private:
    int **m;
    int row,col;
    public:
    Matrix(int r,int c){
        row=r;
        col=c;
        m=new int*[row];
        for(int i=0;i<row;i++){
            m[i]=new int[col];
        }
     }   
    void printMatrix(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void accept(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>m[i][j];
            }
        }
    }

    void add(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                m[i][j]=m[i][j]+1;
            }
        }
        printMatrix();
    }
    void subtract(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                m[i][j]=m[i][j]-1;
            }
        }
        printMatrix();
    }
    void multiply(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                m[i][j]=m[i][j]*2;
            }
        }
        printMatrix();
    }
    void transpose(){
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                int temp=m[j][i];
                m[j][i]=m[i][j];
                m[i][j]=temp;
            }
        }
        printMatrix();
    }
    ~Matrix(){
        for(int i=0;i<row;i++){
            delete[] m[i];
            m[i]=NULL;
        }
        delete[] m;
        m=NULL;
    }
};

int main(){
    int r,c;
    cout<<"Enter the number of rows and columns: ";
    cin>>r>>c;
    Matrix m(r,c);
    m.accept();
    m.add();
    m.subtract();
    m.multiply();
    m.transpose();
    return 0;
}