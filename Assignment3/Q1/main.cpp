#include "Cylinder.h"


  enum EMenu
{
    EXIT,
    ACCEPT_RADIUS_AND_HEIGHT,
    DISPLAY_VOLUME,
    SET_RADIUS,
    SET_HEIGHT,
    GET_RADIUS_AND_HEIGHT
};
int main(){
 
  int choice = 0;
  int radius, height;
   Cylinder *c;

    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. Accept Radius and Height" << endl;
        cout << "2. Display Volume" << endl;
        cout << "3. Set Radius" << endl;
        cout << "4. Set Height" << endl;
        cout << "5. Get Radius And Height" << endl;
        cout << "Enter choice - ";
        cin >> choice;

        switch (EMenu(choice))
        {
        case EXIT:
            delete c;
            c = NULL;
            cout << "Thank you" << endl;
            break;
        case ACCEPT_RADIUS_AND_HEIGHT:
              cout<<"Enter The Radius:: "<<endl;
              cin>>radius;
              cout<<"Enter The Height:: "<<endl;
              cin>>height;
             c = new Cylinder(radius, height);
            break;
        case DISPLAY_VOLUME:
            c->printVolume();
            break;
        case SET_RADIUS:
            cout<<"Enter The New Radius:: "<<endl;
              cin>>radius;
              c->setRadius(radius);
            break;
        case SET_HEIGHT:
           cout<<"Enter The New Height:: "<<endl;
              cin>>height;
              c->setHeight(height);
            break;
        case GET_RADIUS_AND_HEIGHT:
           cout<<"Radius :: "<<c->getRadius()<<" Height :: "<<c->getHeight()<<" Volume Of The Cylinder :: "<<c->getVolume()<<endl;
          break;    
        default:
            cout << "Wrong choice..." << endl;
            break;
        }

    } while (choice != 0);
    return 0;
};   
   