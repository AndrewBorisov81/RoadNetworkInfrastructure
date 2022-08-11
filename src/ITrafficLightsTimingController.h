//
//  ITrafficLightsTimingController.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 20.02.2022.
//

#pragma once

class ITrafficLightsTimingController
{
public:
    virtual void init() = 0;
    virtual void reset() = 0;
    virtual void update() = 0;
    
    virtual void sendSwitchSignal() = 0;
    
    virtual ~ITrafficLightsTimingController() = default;
};

