//
//  Building.hpp
//  
//
//  Created by Nick Hardy on 11/20/21.
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Building:public GameObject{
public:
    void AddOneStudent();
    void RemoveOneStudent();
    void ShowStatus();
    bool ShouldBeVisible();
    Building();
    Building(char, int, Point2D);
private:
    unsigned int student_count;
};



#endif /* Building_hpp */
