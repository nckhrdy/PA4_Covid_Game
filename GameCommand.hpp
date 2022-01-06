//
//  GameCommand.hpp
//  
//
//  Created by Nick Hardy on 11/23/21.
//

#ifndef GameCommand_hpp
#define GameCommand_hpp

#include <stdio.h>
#include <stdlib.h>
#include "Model.hpp"
using namespace std;

void DoMoveCommand(Model& , int, Point2D);
void DoMoveToDoctorCommand(Model&, int, int);
void DoMoveToClassCommand(Model&, int, int);
void DoStopCommand(Model&, int);
void DoLearningCommand(Model&, int, unsigned int);
void DoRecoverInOfficeCommand(Model&, int, unsigned int);
void DoGoCommand(Model&, View&);
void DoRunCommand(Model&, View&);
void InputCases(char,int, Point2D);

#endif /* GameCommand_hpp */
