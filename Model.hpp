//
//  Model.hpp
//
//
//  Created by Nick Hardy on 11/22/21.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include <stdlib.h>
#include "GameObject.hpp"
#include "Student.hpp"
#include "DoctorsOffice.hpp"
#include "ClassRoom.hpp"
#include "View.hpp"

using namespace std;

class Model{
public:
    Model();
    ~Model();
    Student * GetStudentPtr(int);
    DoctorsOffice * GetDoctorsOfficePtr(int);
    ClassRoom * GetClassRoomPtr(int);
    bool Update();
    void Display(View&);
    void ShowStatus();
    int GetNumObj();
    int GetNumStud();
    int GetNumDoc();
    int GetNumClas();
private:
    int time;
    GameObject* object_ptrs[10];
    int num_objects;
    Student* student_ptrs[10];
    int num_students;
    DoctorsOffice* office_ptrs[10];
    int num_offices;
    ClassRoom* class_ptrs[10];
    int num_class;
};

#endif /* Model_hpp */
