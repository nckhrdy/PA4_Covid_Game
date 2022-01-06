//
//  Vector2D.cpp
//  
//
//  Created by Nick Hardy on 11/8/21.
//

#include "Vector2D.hpp"
using namespace std;

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

Vector2D operator * (Vector2D v1, double d)
{
    return Vector2D(v1.x * d, v1.y * d);
}

Vector2D operator / (Vector2D v1, double d)
{
    if (d == 0)
    {
        return v1;
    }
    else {
        return Vector2D(v1.x / d, v1.y / d);
    }
    
}

ostream& operator << (ostream& out, Vector2D v1)
{
    out<<"<"<<v1.x<<","<<v1.y<<">";
    return out;
}
