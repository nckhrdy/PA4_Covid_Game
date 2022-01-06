//
//  Point2D.hpp
//  
//
//  Created by Nick Hardy on 11/8/21.
//

#ifndef Point2D_hpp
#define Point2D_hpp

#include "Vector2D.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

class Point2D{
 public:
    double x;
    double y;
    Point2D();
    Point2D(double, double);
};

double GetDistanceBetween(Point2D, Point2D);

Point2D operator + (Point2D, Vector2D);

Vector2D operator - (Point2D, Point2D);

ostream& operator << (ostream&, Point2D);

bool operator == (Point2D, Point2D);

#endif /* Point2D_hpp */
