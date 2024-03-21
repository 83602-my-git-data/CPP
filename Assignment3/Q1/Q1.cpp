/*Q1. Write a class to find volume of a Cylinder by using following members. (volume of 
Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI) 
Class having following member functions:
Initialize members using constructor member initializer list.
Optional – Use the Modular Apporach*/

#include "Cylinder.h"

Cylinder::Cylinder():Cylinder(1,1)
{
}

Cylinder::Cylinder(double radius, double height){
  this->radius = radius;
  this->height = height;
}

void Cylinder::setRadius(double radius){
  this->radius = radius;
}
void Cylinder::setHeight(double height){
  this->height = height;
}

double Cylinder::getRadius(){
   return this->radius;
}

double Cylinder::getHeight(){
  return this->height;
}
double Cylinder::getVolume(){
  return 3.14 * radius * radius *height;
}

void Cylinder::printVolume(){
  cout<<"Volume of cylinder ::--"<<this->getVolume()<<endl;
}


const double Cylinder::PI =3.14;