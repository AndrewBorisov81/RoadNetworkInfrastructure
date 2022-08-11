//
//  ControllerStateMachine.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 20.02.2022.
//

#pragma once
enum class StatesController { NONE, NEXT_LIGHT, DELAY };

class ControllerStateMachine
{
public:
    ControllerStateMachine();
    virtual ~ControllerStateMachine() = default;
};
