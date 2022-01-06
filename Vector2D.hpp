//
//  Vector2D.hpp
//  
//
//  Created by Nick Hardy on 11/8/21.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Vector2D {
 public:
    double x;
    double y;
    Vector2D();
    Vector2D(double, double);
};

Vector2D operator * (Vector2D, double);
Vector2D operator / (Vector2D, double);
ostream& operator << (ostream&, Vector2D);

#endif /* Vector2D_hpp */
