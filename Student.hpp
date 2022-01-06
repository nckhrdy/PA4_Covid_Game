//
//  Student.hpp
//  
//
//  Created by Nick Hardy on 11/22/21.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include "Point2D.hpp"
#include "Vector2D.hpp"
#include "GameObject.hpp"
#include "ClassRoom.hpp"
#include "DoctorsOffice.hpp"


class Student:public GameObject{
    enum StudentStates
    {
        STOPPED = 0,
        MOVING = 1,
        INFECTED = 2,
        AT_DOCTORS = 3,
        IN_CLASS = 4,
        MOVING_TO_DOCTOR = 5,
        MOVING_TO_CLASS = 6,
        STUDYING_IN_CLASS = 7,
        RECOVERING_ANTIBODIES = 8
    };
    bool UpdateLocation();
    void SetupDestination(Point2D);
    static double GetRandomAmountOfDollars();
public:
    Student();
    Student(char);
    Student(string, int, char, unsigned int, Point2D);
    void StartMoving(Point2D);
    void StartMovingToClass(ClassRoom*);
    void StartMovingToDoctor(DoctorsOffice*);
    void StartLearning(unsigned int);
    void StartRecoveringAntibodies(unsigned int);
    void Stop();
    bool IsInfected();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();
    virtual ~Student();
private:
    double speed;
    bool is_at_doctor;
    bool is_in_classr;
    unsigned int antibodies;
    unsigned int credits;
    double dollars;
    unsigned int assignments_to_buy;
    unsigned int vaccines_to_buy;
    string name;
    DoctorsOffice* current_office;
    ClassRoom* current_class;
    Point2D destination;
    Vector2D delta;
};

#endif /* Student_hpp */
