//
//  GameCommand.cpp
//  
//
//  Created by Nick Hardy on 11/23/21.
//

#include "GameCommand.hpp"
#include <iostream>
using namespace std;

void DoMoveCommand(Model & model, int student_id, Point2D p1)
{
    if(model.GetStudentPtr(student_id) == 0)
        cout<<"Error: Please enter a valid command!"<<endl;
    else
    {
        model.GetStudentPtr(student_id)->StartMoving(p1);
        cout<<"Moving "<<model.GetStudentPtr(student_id)->GetName()<<" to "<<p1<<endl;
    }
}
void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{
    if (model.GetStudentPtr(student_id) == 0 && model.GetDoctorsOfficePtr(office_id) == 0)
        cout<<"Error: Please enter a valid command!"<<endl;
    else
    {
        model.GetStudentPtr(student_id)->StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
        cout<<"Moving "<<model.GetStudentPtr(student_id)->GetName()<<" to DoctorsOffice "<<office_id<<endl;
    }
}
void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
    if (model.GetNumStud() < student_id || model.GetNumClas() < class_id)
    {
        cout<<"Error: Please enter a valid command!"<<endl;
    }
    else
    {
        cout<<"Moving "<<model.GetStudentPtr(student_id)->GetName()<<" to ClarrRoom "<<class_id<<endl;
    }
}
void DoStopCommand(Model & model, int student_id)
{
    if(model.GetNumStud() >= student_id)
    {
        cout<<"Stopping "<<model.GetStudentPtr(student_id)->GetName()<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
    if (model.GetNumStud() >= student_id)
    {
        model.GetStudentPtr(student_id)->StartLearning(assignments);
//        cout<<"*****random test*****"<<endl;
        if (model.GetStudentPtr(student_id)->GetState() == 7)
                cout<<"Teaching "<<model.GetStudentPtr(student_id)->GetName()<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    if (model.GetNumStud() >= student_id)
    {
        model.GetStudentPtr(student_id)->StartRecoveringAntibodies(vaccine_needs);
        cout<<"*****random test*****"<<endl;
        if (model.GetStudentPtr(student_id)->GetState() == 8)
            cout<<"Recovering "<<model.GetStudentPtr(student_id)->GetName()<<"'s antibodies"<<endl;
    }
    else
        cout<<"Error: Please enter a valid command!"<<endl;
}
void DoGoCommand(Model& model, View& view)
{
    cout<<"Advancing one tick"<<endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}
void DoRunCommand(Model& model, View& view)
{
    cout<<"Advancing to next event"<<endl;
    int count = 0;
    bool runCommand = false;
    while (count < 5 && !runCommand)
    {
        runCommand = model.Update();
        count++;
    }
    model.ShowStatus();
    model.Display(view);
    
}


