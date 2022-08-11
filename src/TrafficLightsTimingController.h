//
//  TrafficLightsTimingController.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 20.02.2022.
//

#pragma once
#include "ITrafficLightsTimingController.h"

class TrafficLightsTimingController : public ITrafficLightsTimingController
{
public:
    TrafficLightsTimingController();
    virtual ~TrafficLightsTimingController() = default;
    
    virtual void init() override;
    virtual void reset() override;
    virtual void update() override;
    virtual void sendSwitchSignal() override;
};
