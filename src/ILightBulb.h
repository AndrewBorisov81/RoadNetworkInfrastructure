//
//  ILightBulb.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 18.02.2022.
//

#pragma once

class ILightBulb
{
public:
    virtual void On() = 0;
    virtual void Off() = 0;
    
    virtual ~ILightBulb() = default;
};
