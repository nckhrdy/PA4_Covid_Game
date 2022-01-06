//
//  GameObject.hpp
//  
//
//  Created by Nick Hardy on 11/11/21.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Vector2D.hpp"
#include "Point2D.hpp"
class GameObject
{
public:
    Point2D location;
    int id_num;
    char display_code;
    char state;
    GameObject(char);
    GameObject(Point2D, int, char);
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual void ShowStatus();
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
    void DrawSelf(char * ptr);
    virtual ~GameObject();
};


#endif /* GameObject_hpp */
