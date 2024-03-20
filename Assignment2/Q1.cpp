/* Write a menu driven program to calculate volume of the box(length * width * height).
Provide necessary constructors*/

#include <iostream>
using namespace std; 

class Box{
    private:
     float length, width, height;

    public:
     Box(){
         length = 0;
         width = 0;
         height = 0;
     }
      Box(float length, float width, float height){
        this->length = length;
        this->width = width;
        this->height = height;
      } 
     float volume(){
        return length * width * height;
     } 
};

int main(){
    int choice = 0;
    float length, width, height;
    Box *box = new Box();
    do{
         cout<<"0.Exits"<<endl;
         cout<<"1.Enter Length , Width and Height"<<endl;
         cout<<"2.Calculate Volume "<<endl;

         cout<<"Enter your choice: ";
         cin>>choice;

            switch(choice){
            case 0:
                break;
            case 1:
                cout<<endl;
                cout<<"Enter Length: ";
                cin>>length;
                cout<<"Enter Width: ";
                cin>>width;
                cout<<"Enter Height: ";
                cin>>height;

                box = new Box(length,width,height);
                break;
            case 2:
                cout<<"Volume: "<<box->volume()<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
         }
    }while(choice!= 0);

    return 0;
};   