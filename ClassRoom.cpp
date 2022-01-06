//
//  ClassRoom.cpp
//  
//
//  Created by Nick Hardy on 11/21/21.
//

#include "ClassRoom.hpp"


ClassRoom::ClassRoom()
{
    display_code = 'C';
    state = NOT_PASSED;
    max_number_of_assignments = 10;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = 1;
    dollar_cost_per_assignment = 1.0;
    credits_points_per_assignment = 2;
    cout<<"ClassRoom default constructed"<<endl;
}
ClassRoom::ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc)
{
    display_code = 'C';
    state = NOT_PASSED;
    id_num = in_id;
    max_number_of_assignments = max_assign;
    antibody_cost_per_assignment = antibody_cost;
    credits_points_per_assignment = crd_per_assign;
    dollar_cost_per_assignment = dollar_cost;
    location = in_loc;
    cout<<"ClassRoom constructed"<<endl;
}
double ClassRoom::GetDollarCost(unsigned int unit_qty)
{
    return dollar_cost_per_assignment * unit_qty;
}
unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty)
{
    return antibody_cost_per_assignment * unit_qty;
}
unsigned int ClassRoom::GetNumAssignmentsRemaining()
{
    return num_assignments_remaining;
}
bool ClassRoom::IsAbleLearn(unsigned int unit_qty, double budget, unsigned int antibodies)
{
    if (budget >= GetDollarCost(unit_qty) && antibodies >= GetAntibodyCost(unit_qty))
        return true;
    else
        return false;
}
unsigned int ClassRoom::TrainStudents(unsigned int assignment_units)
{
    if (num_assignments_remaining > assignment_units)
    {
        num_assignments_remaining = num_assignments_remaining - assignment_units;
        return num_assignments_remaining * credits_points_per_assignment;
    }
  else
  {
      num_assignments_remaining = 0;
      return assignment_units * credits_points_per_assignment;
  }
}
bool ClassRoom::Update()
{
    if (num_assignments_remaining == 0 && state == NOT_PASSED)
    {
        state = PASSED;
        display_code = 'c';
        cout<<display_code<<" "<<id_num<<" Has been passed"<<endl;
        return true;
    }
    else
        return false;
    
}
bool ClassRoom::passed()
{
    if (num_assignments_remaining == 0)
        return true;
    else
        return false;
}
void ClassRoom::ShowStatus()
{
    cout<<"ClassRoomStatus: "<<endl;
    Building::ShowStatus();
    cout<<" Max number of assignments: "<<max_number_of_assignments<<endl;
    cout<<"Antibody cost per assignment: "<<antibody_cost_per_assignment<<endl;
    cout<<"Dollar cost per assignment: "<<dollar_cost_per_assignment<<endl;
    cout<<"Credits per assignment: "<<credits_points_per_assignment<<endl;
    cout<<num_assignments_remaining<<" assignments are remaining for this ClassRoom"<<endl;
}

ClassRoom::~ClassRoom()
{
    cout<<"ClassRoom destructed"<<endl;
}
