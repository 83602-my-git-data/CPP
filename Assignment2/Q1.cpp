/* Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options -> 
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values*/

#include <iostream>
using namespace std; 

class Box{
    private:
     float length, width, height;

    public:
     Box():Box(0,0,0){
        cout<<" parameterless constructor"<<endl;
     }

     Box(float length):Box(length,length,length){
            cout<<"1 parameterized constructor"<<endl;
     };

      Box(float length, float width, float height){
        cout<<"3 parameterized constructor"<<endl;
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
   // Box *box = new Box();
    do{
         cout<<"0.Exits"<<endl;
         cout<<"1. 3 parameterized constructor"<<endl;
         cout<<"2. 1 parameterized constructor"<<endl;
         cout<<"3.0 parameterized constructor"<<endl;

         cout<<"Enter your choice: ";
         cin>>choice;

            switch(choice){
            case 0:
                break;
            case 1:{
                cout<<endl;
                cout<<"Enter Length: ";
                cin>>length;
                cout<<"Enter Width: ";
                cin>>width;
                cout<<"Enter Height: ";
                cin>>height;

             Box box = Box(length,width,height);
               cout<<"Volume ::- "<<box.volume()<<endl;
               
            };
            break;
            case 2:{
                    cout<<"Enter Length :: "<<endl;
                    cin>>length;
                    cout<<"Volume :: "<<Box(length).volume()<<endl;
                };
                break;

             case 3:{
                    cout<<"Volume :: "<<Box().volume()<<endl;
                };
                break;    
            default:
                cout<<"Invalid choice"<<endl;
                break;
         }
    }while(choice!= 0);

    return 0;
};   