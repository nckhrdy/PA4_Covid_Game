//
//  main.cpp
//  
//
//  Created by Nick Hardy on 11/23/21.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Vector2D.hpp"
#include "Point2D.hpp"
#include "GameObject.hpp"
#include "Building.hpp"
#include "ClassRoom.hpp"
#include "DoctorsOffice.hpp"
#include "Student.hpp"
#include "Model.hpp"
#include "GameCommand.hpp"
#include "View.hpp"


using namespace std;
int main()
{
    bool run = 1;
    char input = ' ';
    int student_id, office_id, class_id;
    unsigned int assignments, vaccine_needs;
    Point2D p1;
    
    Model* m1 = new Model();
    View* v1  = new View();
    m1->ShowStatus();
    m1->Display(*v1);
    
    while (run)
    {
        cout << "Enter a game command ";
        cin >> input;
        
        switch (input)
        {
            case 'm':
                cout<<"Enter student id: ";
                cin>>student_id;
                cout<<"Enter a point: ";
                cin>>p1.x>>p1.y;
                DoMoveCommand(*m1, student_id, p1);
                m1->Display(*v1);
                break;
                
            case 'd':
                cout<<"Enter student id: ";
                cin>>student_id;
                cout<<"Enter office id: ";
                cin>>office_id;
                DoMoveToDoctorCommand(*m1,student_id,office_id);
                m1->Display(*v1);
                break;
        
            case 'c':
                cout<<"Enter student id: ";
                cin>>student_id;
                cout<<"Enter class id: ";
                cin>>class_id;
                DoMoveToClassCommand(*m1,student_id,class_id);
                m1->Display(*v1);
                break;
                
            case 's':
                cout<<"Enter student id: ";
                cin>>student_id;
                DoStopCommand(*m1,student_id);
                m1->Display(*v1);
                break;
                
            case 't':
                cout<<"Enter student id: ";
                cin>>student_id;
                cout<<"Enter number of assignments: ";
                cin>>assignments;
                DoLearningCommand(*m1, student_id, assignments);
                m1->Display(*v1);
                break;
                
            case 'v':
                cout<<"Enter student id: ";
                cin>>student_id;
                cout<<"Enter number of vaccines: ";
                cin>>vaccine_needs;
                DoRecoverInOfficeCommand(*m1, student_id, vaccine_needs);
                m1->Display(*v1);
                break;
                
            case 'g':
                DoGoCommand(*m1, *v1);
                m1->ShowStatus();
                m1->Display(*v1);
                break;
                
            case 'x':
                DoRunCommand(*m1, *v1);
                m1->ShowStatus();
                m1->Display(*v1);
                break;
                
            case 'q':
                exit(0);
            default:
                break;
        }
    }
    return 0;
}
