#ifndef CYLINDER_H
#define CYLINDER_H
 
#include <iostream>
using namespace std;


class Cylinder{
  double radius;
  double height;
  static const double PI;

  public: 
    Cylinder();
    Cylinder(double radius, double height);
    double getRadius();
    void setRadius(double radius);
    double getHeight();
    void setHeight(double height);

    double getVolume();

    void printVolume();

};


#endif