//
//  DoctorsOffice.cpp
//  
//
//  Created by Nick Hardy on 11/21/21.
//

#include "DoctorsOffice.hpp"

DoctorsOffice::DoctorsOffice()
{
    display_code = 'D';
    vaccine_capacity = 100;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 5;
    state = VACCINE_AVAILABLE;
    cout<<"DoctorsOffice default constructed"<<endl;
}
DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc)
{
    display_code = 'D';
    vaccine_capacity = 100;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 5;
    id_num = in_id;
    location = in_loc;
    state = VACCINE_AVAILABLE;
    cout<<"DoctorsOffice constructed"<<endl;
}
bool DoctorsOffice::HasVaccine()
{
    if (num_vaccine_remaining >= 1)
        return true;
    else
        return false;
}
unsigned int DoctorsOffice::GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}
bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget)
{
    if (budget >= vaccine*dollar_cost_per_vaccine)
        return true;
    else
        return false;
}
double DoctorsOffice::GetDollarCost(unsigned int vaccine)
{
    return vaccine * dollar_cost_per_vaccine;
}
unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed)
{
    if (num_vaccine_remaining >= vaccine_needed)
    {
        num_vaccine_remaining = num_vaccine_remaining - vaccine_needed;
        return num_vaccine_remaining;
    }
    else
    {
        return num_vaccine_remaining;
        num_vaccine_remaining = 0;
    }
}
bool DoctorsOffice::Update()
{
    if (num_vaccine_remaining == 0 && state == VACCINE_AVAILABLE)
    {
        state = NO_VACCINE_AVAILABLE;
        display_code = 'd';
        cout<<"DoctorsOffice "<<id_num<<" has ran out of vaccine."<<endl;
        return true;
    }
    else
        return false;
}
void DoctorsOffice::ShowStatus()
{
    cout<<"DoctorsOffice Status: "<<endl;
    Building::ShowStatus();
    cout<<"Dollars per vaccine: "<<dollar_cost_per_vaccine<<" has "<<num_vaccine_remaining<<" vaccine(s) remaining"<<endl;
}
DoctorsOffice::~DoctorsOffice()
{
    cout<<"DoctorsOffice destructed"<<endl;
}
