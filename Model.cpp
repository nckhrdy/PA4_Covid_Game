//
//  Model.cpp
//  
//
//  Created by Nick Hardy on 11/22/21.
//

#include "Model.hpp"
#include <iostream>
using namespace std;
Model::Model()
{
    time = 0;
    //student 1
    Point2D p1(5,1);
    student_ptrs[0] = new Student("Homer",1,'S',14,p1);
    object_ptrs[0] = student_ptrs[0];
    //student 2
    Point2D p2(10,1);
    student_ptrs[1] = new Student("Marge",2,'S',15,p2);
    object_ptrs[1] = student_ptrs[1];
    //DoctorsOffice 1
    Point2D p3(1,20);
    office_ptrs[0] = new DoctorsOffice(1,1,20,p3);
    object_ptrs[2] = office_ptrs[0];
    //DoctorsOffice 2
    Point2D p4(10,20);
    office_ptrs[1] = new DoctorsOffice(2,2,200,p4);
    object_ptrs[3] = office_ptrs[1];
    //ClassRoom 1
    Point2D p5(0,0);
    class_ptrs[0] = new ClassRoom(20,5,7.5,4,1,p5);
    object_ptrs[4] = class_ptrs[0];
    //ClassRoom 2
    Point2D p6(5,5);
    class_ptrs[1] = new ClassRoom(20,5,7.5,4,2,p6);
    object_ptrs[5] = class_ptrs[1];
    //Virus 1
//    Point2D p7(10,12);
//    virus_ptrs[0] = new Virus();
//    object_ptrs[6] = virus _ptrs[0];
//    //Virus 2
//    Point2D p8(15,5);
//    virus_ptrs[1] = new Virus();
//    object_ptrs[7] = virus _ptrs[1];
//    
    num_objects = 6;
    num_students = 2;
    num_offices = 2;
    num_class = 2;
//    num_virus = 2;
    
    cout<<"Model default Constructed"<<endl;
    
}
bool Model::Update()
{
    time ++;
    bool updated = false;
    for (int i = 0; i < num_objects; i++)
    {
        if (object_ptrs[i]->Update())
            return true;
    }
    if (class_ptrs[0]->passed() == true && class_ptrs[1]->passed() == true)
    {
        cout<<"GAME OVER: You win! All assignments done!"<<endl;
        exit (EXIT_SUCCESS);
    }
    if (student_ptrs[0]->IsInfected() == true && student_ptrs[1]->IsInfected() == true)
    {
        cout<<"GAME OVER: You lose! All of your Students are infected!"<<endl;
        exit (EXIT_SUCCESS);
    }
}
void Model::Display(View& view)
{
    cout<<"Time: "<<time<<endl;
    view.Clear();
    for (int i = 0; i < num_objects; i++)
    {
        view.Plot(object_ptrs[i]);
    }
    view.Draw();
}
void Model::ShowStatus()
{
    cout<<"Time: "<<time<<endl;
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}
Student * Model::GetStudentPtr(int id)
{
    for (int i = 0; i < num_students; i++)
    {
        if (student_ptrs[i]->GetId() == id)
            return student_ptrs[i];
    }
    return 0;
}
DoctorsOffice * Model::GetDoctorsOfficePtr(int id)
{
    for (int i = 0; i < num_offices; i++)
    {
        if (office_ptrs[i]->GetId() == id)
            return office_ptrs[i];
    }
    return 0;
}
ClassRoom * Model::GetClassRoomPtr(int id)
{
    for (int i = 0; i < num_class; i++)
    {
        if (class_ptrs[i]->GetId() == id)
            return class_ptrs[i];
    }
    return 0;
}
int Model::GetNumObj()
{
    return num_objects;
}
int Model::GetNumStud()
{
    return num_students;
}
int Model::GetNumDoc()
{
    return num_offices;
}
int Model::GetNumClas()
{
    return num_class;
}
Model::~Model()
{
    for (int i = 0; i < 6; i++)
    {
        delete object_ptrs[i];
        cout<<"Model destructed"<<endl;
    }
}
