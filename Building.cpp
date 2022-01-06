//
//  Building.cpp
//  
//
//  Created by Nick Hardy on 11/20/21.
//

#include "Building.hpp"

using namespace std;

Building::Building():GameObject('B')
{
    student_count = 0;
    cout<<"Building default constructed"<<endl;
}
Building::Building(char in_code, int in_id, Point2D in_loc):GameObject(in_loc,in_id,in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    student_count = 0;
    state = 0;
    cout<<"Building constructed"<<endl;
}
void Building::AddOneStudent()
{
    //cout<<"*******test this shit*****"<<endl;
    student_count++;
}
void Building::RemoveOneStudent()
{
    if (student_count > 0)
        student_count--;
}
void Building::ShowStatus()
{
    GameObject::ShowStatus();
    if (student_count > 1 || student_count < 1)
        cout<<" "<<this->student_count<<" students are in this building"<<endl;
    else
        cout<<" "<<this->student_count<<" student is in this building"<<endl;
}
bool Building::ShouldBeVisible()
{
    return true; 
}
