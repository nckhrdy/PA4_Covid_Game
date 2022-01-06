//
//  View.hpp
//  
//
//  Created by Nick Hardy on 11/23/21.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include <iostream>
#include "Point2D.hpp"
#include "GameObject.hpp"
const int view_maxsize = 20;
class View{
public:
    View();
    void Clear();
    void Plot(GameObject*);
    void Draw();
private:
    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    bool GetSubscripts(int &out_x, int &out_y, Point2D location);
    
};

#endif /* View_hpp */
