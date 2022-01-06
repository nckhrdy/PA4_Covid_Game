//
//  Student.cpp
//  
//
//  Created by Nick Hardy on 11/22/21.
//

#include "Student.hpp"
#include <math.h>
#include <time.h>
using namespace std;

Student::Student():GameObject('S')
{
    speed = 5;
    is_at_doctor = false;
    is_in_classr = false;
    antibodies = 20;
    credits = 0;
    dollars = 0;
    name = "";
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    current_office = NULL;
    current_class = NULL;
    cout<<"Student default constructed"<<endl;
}
Student::Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc,in_id,in_code)
{
    speed = in_speed;
    is_at_doctor = false;
    is_in_classr = false;
    antibodies = 20;
    credits = 0;
    dollars = 0;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    current_office = NULL;
    current_class = NULL;
    name = in_name;
    id_num = in_id;
    display_code = in_code;
    location = in_loc;
    cout<<"Student constructed"<<endl;
}
void Student::StartMoving(Point2D dest)
{
    if (!IsInfected())
    {
        if((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y)) <= delta.y)
        {
            cout<<display_code<<GetId()<<": I'm alreadt there. See?"<<endl;
        }
        else
        {
            state = MOVING;
            SetupDestination(dest);
            cout << display_code << GetId() << ": On my way." << endl;
        }
    }
    else
    {
        cout << display_code << GetId() << ": I am infected. I may move but you just cannot see me. " << endl;
    }
//    SetupDestination(dest);
//    state = MOVING;
//    if((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y)) <= delta.y)
//    {
//        state = STOPPED;
//        cout<<display_code<<" "<<id_num<<": I'm alreadt there. See?"<<endl;
//    }
//    else if(!IsInfected())
//    {
//        if (dest == this->GetLocation())
//        {
//        cout<<display_code<<" "<<id_num<<":I am infected. I may move but you cannot see me."<<endl;
//    }
//    else
//    {
//        state = MOVING;
//        cout<<display_code<<" "<<id_num<<":On my way."<<endl;
//    }
}
void Student::StartMovingToClass(ClassRoom * classr)
{
    //tell student to start moving to a ClassRoom
    if(!IsInfected()) //if the student is infected
    {
      if (location == classr->GetLocation())
      {
          cout<<display_code<<" "<<GetId()<<": I'm already at the Classroom!"<<endl;
      }
        else
        {
            if (is_in_classr)
            {
                current_class->RemoveOneStudent();
                is_in_classr = false;
            }
            else if (is_at_doctor)
            {
                current_office->RemoveOneStudent();
                is_at_doctor = false;
            }
            state = MOVING_TO_CLASS;
            current_class = classr;
            SetupDestination(classr->GetLocation());
            cout<<display_code<<GetId()<<": On my way to class"<<classr->GetId()<<endl;
        }
    }
    else
    {
        cout<<display_code<<" "<<GetId()<<": I am infected so I can't move to class..."<<endl;
    }
}
void Student::StartMovingToDoctor(DoctorsOffice * office)
{
    current_office = office;
    SetupDestination(current_office->GetLocation());
    if (!IsInfected())
    {
        if (location == office->GetLocation())
     {
         cout<<display_code<<GetId()<<": I am already at the Doctor's!"<<endl;
     }
        else
        {
            if(is_at_doctor)
            {
                current_office->RemoveOneStudent();
                is_at_doctor = false;
            }
            else if (is_in_classr)
            {
                current_class->RemoveOneStudent();
                is_in_classr = false;
            }
            state = MOVING_TO_DOCTOR;
            current_office = office;
            SetupDestination(office->GetLocation());
            cout<<display_code<<GetId()<<": On my way to Doctor's Office "<<office->GetId()<<endl;
        }
    }
    else
    {
        cout<<display_code<<" "<<GetId()<<":I am infected so I should have gone to the doctor's"<<endl;
//        cout<<"***"<<current_office->GetId();
    }
}
void Student::StartLearning(unsigned int num_assignments)
{
    unsigned int assignments_in_class = 0;
    //tell student to start learning num_assignments in ClassRoom
    if (!IsInfected())
    {
        if (state == IN_CLASS || state == STUDYING_IN_CLASS)
        {
            if(current_class->IsAbleLearn(num_assignments, dollars, antibodies))
            {
                if (!current_class->passed())
                {
                    assignments_in_class = current_class->GetNumAssignmentsRemaining();
                    assignments_to_buy = min(num_assignments, assignments_in_class);
                    cout<<display_code<<GetId()<<": Started to lean at ClassRoom "<<current_class->GetId()<<" with "<<assignments_to_buy<<" assignments"<<endl;
                }
                else
                    cout<<display_code<<GetId()<<": Cannot learn. Class already passed"<<endl;
            }
            else
                cout<<display_code<<GetId()<<": Not enough antibodies/money for school"<<endl;
        }
        else
            cout<<display_code<<GetId()<<": I can only learn in a ClassRoom"<<endl;
    }
    else
        cout<<display_code<<GetId()<<": I am infected so no I cannot do school"<<endl;
}
void Student::StartRecoveringAntibodies(unsigned int num_vaccines)
{
    unsigned int vaccine_count_in_office = 0;
    if (state == AT_DOCTORS || state == RECOVERING_ANTIBODIES)
    {
        if (IsInfected())
        {
            cout<<display_code<<GetId()<<": I just about made it to the Doctor's office"<<endl;
        }
        if (current_office->CanAffordVaccine(num_vaccines, dollars))
        {
            if(current_office->HasVaccine())
            {
                vaccine_count_in_office = current_office->GetNumVaccineRemaining();
                state = RECOVERING_ANTIBODIES;
                vaccines_to_buy = min(num_vaccines, vaccine_count_in_office);
                cout<<display_code<<GetId()<<": Started recovering at Doctor's Office "<<current_office->GetId()<<endl;
            }
            else
                cout<<display_code<<GetId()<<": Cannot recover! No vaccines remaining in this Doctor's office"<<endl;
        }
        else
            cout<<display_code<<GetId()<<": Not enough money to buy vaccine"<<endl;
    }
    else
        cout<<display_code<<GetId()<<": I can only recover in a Doctor's Office"<<endl;
//    if ( current_office->GetDollarCost(num_vaccines) > dollars )//Student doesnt not have enough dollars
//    {
//        cout<<display_code<<" "<<id_num<<": Not enough money to recover antibodies"<<endl;
//
//    }
//    else if (!(is_at_doctor))//Student is not in a doctors office
//    {
//        cout<<display_code<<" "<<id_num<<": I can only recover antibodies at a Doctor's Office!"<<endl;
//    }
//    else if (!(current_office->HasVaccine()))//Doctor's Office does not have at least 1 vaccine remaining
//    {
//        cout<<display_code<<" "<<id_num<<": Cannot recover! No vaccines remaining in this Doctor's Office"<<endl;
//    }
//    else
//    {
//        vaccines_to_buy = num_vaccines;
//        state = RECOVERING_ANTIBODIES;
//        cout<<display_code<<" "<<id_num<<": Started recovering "<<state<<" antibodies at Doctor's Office"<<current_office->GetId()<<endl;
//    }
}
void Student::Stop()
{
    state = STOPPED;
    cout<<display_code<<" "<<id_num<<": Stopping.."<<endl;
}
bool Student::IsInfected()
{
    return antibodies == 0;
}
bool Student::ShouldBeVisible()
{
    if ( IsInfected() != 1 )
        return true;
    else
        return false;
}
void Student::ShowStatus() //print state specific status info
{
    cout << name << " status: ";
    GameObject::ShowStatus();
    switch (state) {
        case STOPPED:
            cout << " stopped" << endl;
            break;
        case MOVING:
            cout << " moving at a speed of " << speed
                 << " to " << destination << " at each step of " << delta << endl;
            break;
        case MOVING_TO_DOCTOR:
            cout << " heading to Doctor's Office " << current_office->GetId()
                 << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case MOVING_TO_CLASS:
            cout << " heading to Classroom" << current_class->GetId()
                 << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case IN_CLASS:
            cout << " inside Classroom " << current_class->GetId() << endl;
            current_class->AddOneStudent();
            break;
        case AT_DOCTORS:
            cout << " inside Doctor's Office " << current_office->GetId() << endl;
            current_office->AddOneStudent();
            break;
        case STUDYING_IN_CLASS:
            cout << " studying at Classroom " << current_class->GetId() << endl;
        case RECOVERING_ANTIBODIES:
            cout << " recovering antiobodes in Doctor's Office " << current_office->GetId() << endl;
            break;
        case INFECTED:
            cout << endl;
        default:
            break;
    }
    //  Print stats here
    cout << "\tAntibodies: " << antibodies << endl;
    cout << "\tDollars: " << dollars << endl;
    cout << "\tCredits: " << credits << endl;
}
//    cout<<name<<" status: "<<endl;
//    GameObject::ShowStatus();
//    if (state == 0)
//    {
//        cout<<" stopped"<<endl;
//    }
//    else if (state == 1)
//    {
//        cout<<" moving at a speed of "<<speed<<" to destination "<<destination.x<<","<<destination.y<<" at each step of "<<delta<<endl;
//    }
//    else if (state == 2)
//    {
//        cout<<" heading to Classroom"<<current_class->GetId()<<"at a speed of "<<speed<<"at each step of"<<delta<<endl;
//
//    }
//    else if (state == 3)
//    {
//        cout<<" heading to Doctor's Office "<<current_office->GetId()<<" at a speed of "<<speed<<" at each step of"<<delta<<endl;
//    }
//    else if (state == 4)
//    {
//        cout<<" inside Classroom "<<current_class->GetId()<<endl;
//    }
//    else if (state == 5)
//    {
//        cout<<" inside Doctor's Office"<<current_office->GetId()<<endl;
//    }
//    else if (state == 6)
//    {
//        cout<<" studying in Classroom "<<current_class->GetId()<<endl;
//    }
//    else
//    {
//        cout<<" recovering antibodies in Doctor's Office "<<current_office->GetId()<<endl;
//    }
//
//    cout<<"Antibodies: "<<antibodies<<endl;
//    cout<<"Dollars: "<<dollars<<endl;
//    cout<<"Credits: "<<credits<<endl;
//}
//bool Student::Update()
//{
//    bool arrived = false;
//    unsigned int vaccine_received = 0;
//    unsigned int antibody_cost = 0;
//    unsigned int antibody_boost =0;
//    double dollar_cost = 0;
//    unsigned int num_assignments = 0;
//    unsigned int credits_gain = 0;
//    //check how student objects behave
//    if (state == 0)
//    {
//        return false;
//    }
//    else if (state == 1)
//    {
//        if (is_at_doctor) {
//            current_office->RemoveOneStudent();
//            is_at_doctor = false;
//        } else if (is_in_classr) {
//            current_class->RemoveOneStudent();
//            is_in_classr = false;
//        }
//        if (antibodies == 0) {
//            cout << name << " is out of antibodies and can't move." << endl;
//            state = INFECTED;
//            return true;
//        } else {
//            arrived = UpdateLocation();
//            if (arrived) {
//                state = STOPPED;
//                return true;
//            } else {
//                dollars += GetRandomAmountOfDollars();
//                antibodies -= 1;
//                return false;
//            }
//        }
//    }
//    else if (state == 2)
//    {
//        if (is_at_doctor) {
//            current_office->RemoveOneStudent();
//            is_at_doctor = false;
//        } else if (is_in_classr) {
//            current_class->RemoveOneStudent();
//            is_in_classr = false;
//        }
//        if (antibodies== 0) {
//            cout << name << " is out of antibodies and can't move." << endl;
//            state = INFECTED;
//            return true;
//        } else {
//            arrived = UpdateLocation();
//            if (arrived) {
//                state = IN_CLASS;
//                is_in_classr = true;
//                current_class->AddOneStudent();
//                return true;
//            } else {
//                dollars += GetRandomAmountOfDollars();
//                antibodies -= 1;
//                return false;
//            }
//        }
//    }
//    else if (state == 3)
//    {
//        if (is_at_doctor) {
//            current_office->RemoveOneStudent();
//            is_at_doctor = false;
//        } else if (is_in_classr) {
//            current_class->RemoveOneStudent();
//            is_in_classr = false;
//        }
//        if (antibodies == 0) {
//            cout << name << " is out of antibodies and can't move." << endl;
//            state = INFECTED;
//            return true;
//        } else {
//            arrived = UpdateLocation();
//            if (arrived) {
//                state = AT_DOCTORS;
//                is_at_doctor = true;
//                //cout<<"******* random *****"<<endl;
//                current_office->AddOneStudent();
//                return true;
//            } else {
//                dollars += GetRandomAmountOfDollars();
//                antibodies -= 1;
//                return false;
//            }
//        }
//
//    }
//    else if (state == 4)
//    {
//        dollars = GetRandomAmountOfDollars();
//        return false;
//    }
//    else if (state == 5)
//    {
//        dollars = GetRandomAmountOfDollars();
//        return false;
//    }
//    else if (state == 6)
//    {
//        antibody_cost = current_class->GetAntibodyCost(assignments_to_buy);
//        dollar_cost = current_class->GetDollarCost(assignments_to_buy);
//        credits_gain = current_class->TrainStudents(assignments_to_buy);
//        antibodies -= antibody_cost;
//        dollars -= dollar_cost;
//        credits += credits_gain;
//        cout << "** " << name << " completed " << assignments_to_buy << " assignment(s)! **" << endl;
//        cout << "** " << name << " gained " << credits_gain << " credits! **" << endl;
//        assignments_to_buy = 0;
//        state = IN_CLASS;
//        return true;    }
//    else
//    {
//        dollar_cost = current_office->GetDollarCost(vaccines_to_buy);
//        dollars -= dollar_cost;
//        vaccine_received = current_office->DistributeVaccine(vaccines_to_buy);
//        antibody_boost = (5 * vaccine_received);
//        antibodies +=antibody_boost;
//        cout << "** " << name << " bought " << vaccine_received << " vaccine(s)! **" << endl;
//        cout << "** " << name << " recovered " << antibody_boost << " antibodies! **" << endl;
//        vaccines_to_buy = 0;
//        state = AT_DOCTORS;    }
//}
bool Student::Update() {
    bool arrived = false;
    unsigned int vaccine_received = 0;
    unsigned int antibody_cost = 0;
    unsigned int antibody_boost = 0;
    double dollar_cost = 0;
    unsigned int num_assignments = 0;
    unsigned int credits_gain = 0;
    switch (state) {
        case STOPPED:
            return false;
        case MOVING:
            if (is_at_doctor) {
                current_office->RemoveOneStudent();
                is_at_doctor = false;
            } else if (is_in_classr) {
                current_class->RemoveOneStudent();
                is_in_classr = false;
            }
            if (antibodies == 0) {
                cout << name << " is out of antibodies and can't move." << endl;
                state = INFECTED;
                return true;
            } else {
                arrived = UpdateLocation();
                if (arrived) {
                    state = STOPPED;
                    return true;
                } else {
                    dollars += GetRandomAmountOfDollars();
                    antibodies -= 1;
                    return false;
                }
            }
        case MOVING_TO_CLASS:
            if (is_at_doctor) {
                current_office->RemoveOneStudent();
                is_at_doctor = false;
            } else if (is_in_classr) {
                current_class->RemoveOneStudent();
                is_in_classr = false;
            }
            if (antibodies== 0) {
                cout << name << " is out of antibodies and can't move." << endl;
                state = INFECTED;
                return true;
            } else {
                arrived = UpdateLocation();
                if (arrived) {
                    state = IN_CLASS;
                    is_in_classr = true;
                    current_class->AddOneStudent();
                    return true;
                } else {
                    dollars += GetRandomAmountOfDollars();
                    antibodies -= 1;
                    return false;
                }
            }
        case MOVING_TO_DOCTOR:
            if (is_at_doctor) {
                current_office->RemoveOneStudent();
                is_at_doctor = false;
            } else if (is_in_classr) {
                current_class->RemoveOneStudent();
                is_in_classr = false;
            }
            if (antibodies == 0) {
                cout << name << " is out of antibodies and can't move." << endl;
                state = INFECTED;
                return true;
            } else {
                arrived = UpdateLocation();
                if (arrived) {
                    state = AT_DOCTORS;
                    is_at_doctor = true;
                    current_office->AddOneStudent();
                    return true;
                } else {
                    dollars += GetRandomAmountOfDollars();
                    antibodies -= 1;
                    return false;
                }
            }
        case RECOVERING_ANTIBODIES:
            dollar_cost = current_office->GetDollarCost(vaccines_to_buy);
            dollars -= dollar_cost;
            vaccine_received = current_office->DistributeVaccine(vaccines_to_buy);
            antibody_boost = (5 * vaccine_received);
            antibodies +=antibody_boost;
            cout << "** " << name << " bought " << vaccine_received << " vaccine(s)! **" << endl;
            cout << "** " << name << " recovered " << antibody_boost << " antibodies! **" << endl;
            vaccines_to_buy = 0;
            state = AT_DOCTORS;
            return true;
       case STUDYING_IN_CLASS:
            antibody_cost = current_class->GetAntibodyCost(assignments_to_buy);
            dollar_cost = current_class->GetDollarCost(assignments_to_buy);
            credits_gain = current_class->TrainStudents(assignments_to_buy);
            antibodies -= antibody_cost;
            dollars -= dollar_cost;
            credits += credits_gain;
            cout << "** " << name << " completed " << assignments_to_buy << " assignment(s)! **" << endl;
            cout << "** " << name << " gained " << credits_gain << " credits! **" << endl;
            assignments_to_buy = 0;
            state = IN_CLASS;
            return true;
        case INFECTED:
        case IN_CLASS:
        case AT_DOCTORS:
        default:
            return false;
    }
}
bool Student::UpdateLocation()
{
//    if(fabs(destination.x - location.x) <= delta.x && fabs(destination.y - location.y) <= delta.y)
//    {
//        location = destination;
//        cout<<display_code<<id_num<<": I'm there"<<endl;
//        return true;
//    }
//    else
//    {
//        location = location + delta;
//        cout<<display_code<<id_num<<": step.."<<endl;
//        return false;
//    }
    if (fabs((destination - location).x) <= fabs(delta.x) &&
        fabs((destination - location).y) <= fabs(delta.y)) {
        location = destination;
        cout << display_code << GetId() << ": I’m there!" << endl;
        return true;
    }
    else {
        location = location + delta;
        cout << display_code << GetId() << ": step..." << endl;
        return false;
    }
}
void Student::SetupDestination(Point2D dest)
{
    //sets up object to start moving to dest
    destination = dest;
//    if (GetDistanceBetween(destination, location) == 0)
//    {
//        delta.x =0;
//        delta.y =0;
//    }
//    else
        delta = (destination - location) * (speed / GetDistanceBetween(destination,location));
}
double Student::GetRandomAmountOfDollars()//rand num from 0.0 - 2.0
{
    double f_min = 0.0;
    double f_max = 2.0;
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}
string Student::GetName()
{
    return name;
}
Student::~Student()
{
    cout<<"Student destructed"<<endl;
}

