//
//  ITrafficLight.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 18.02.2022.
//

#pragma once
#include "IRoadObject.h"

class ITrafficLight: public IRoadObject
{
public:
    virtual void allow() = 0;
    virtual void disallow() = 0;
    
    virtual ~ITrafficLight() = default;
};
