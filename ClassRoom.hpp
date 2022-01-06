//
//  ClassRoom.hpp
//  
//
//  Created by Nick Hardy on 11/21/21.
//

#ifndef ClassRoom_hpp
#define ClassRoom_hpp

#include <stdio.h>
#include <cmath>
#include "Building.hpp"



class ClassRoom:public Building{
    enum ClassRoomStates{
        NOT_PASSED = 0, PASSED = 1
    };
public:
    ClassRoom();
    ClassRoom(unsigned int, unsigned int, double, unsigned int, int, Point2D);
    double GetDollarCost(unsigned int);
    unsigned int GetAntibodyCost(unsigned int);
    unsigned int GetNumAssignmentsRemaining();
    bool IsAbleLearn(unsigned int, double, unsigned int);
    unsigned int TrainStudents(unsigned int);
    bool Update();
    bool passed();
    void ShowStatus();
    ~ClassRoom();
private:
    unsigned int num_assignments_remaining;
    unsigned int max_number_of_assignments;
    unsigned int antibody_cost_per_assignment;
    double dollar_cost_per_assignment;
    unsigned int credits_points_per_assignment;
};

#endif /* ClassRoom_hpp */
