//
//  DoctorsOffice.hpp
//  
//
//  Created by Nick Hardy on 11/21/21.
//

#ifndef DoctorsOffice_hpp
#define DoctorsOffice_hpp

#include <stdio.h>
#include <cmath>
#include "Building.hpp"

class DoctorsOffice:public Building {
    enum DoctorsOfficeStates {
        VACCINE_AVAILABLE = 0, NO_VACCINE_AVAILABLE = 1
    };
public:
    DoctorsOffice();
    DoctorsOffice(int, double, unsigned int, Point2D);
    bool HasVaccine();
    unsigned int GetNumVaccineRemaining();
    bool CanAffordVaccine(unsigned int, double);
    double GetDollarCost(unsigned int);
    unsigned int DistributeVaccine(unsigned int);
    bool Update();
    void ShowStatus();
    ~DoctorsOffice();
private:
    unsigned int vaccine_capacity;
    unsigned int num_vaccine_remaining;
    double dollar_cost_per_vaccine;
};

#endif /* DoctorsOffice_hpp */
