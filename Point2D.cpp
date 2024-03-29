//
//  Point2D.cpp
//  
//
//  Created by Nick Hardy on 11/8/21.
//

#include "Point2D.hpp"
using namespace std;

Point2D::Point2D() //default constructor
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    return sqrt( pow( (p1.x - p2.x), 2.0) + pow( (p1.y - p2.y), 2.0) );
}

Point2D operator + (Point2D p1, Vector2D v1)
{
    return Point2D(p1.x + v1.x, p1.y + v1.y);
}

Vector2D operator - (Point2D p1, Point2D p2)
{
    return Vector2D(p1.x - p2.x, p1.y - p2.y);
}

ostream& operator << (ostream& out, Point2D p1)
{
    return out<<"("<<p1.x<<","<<p1.y<<")";
}

bool operator == (Point2D p1, Point2D p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
        return true;
    return false;
}
