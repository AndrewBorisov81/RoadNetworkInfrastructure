//
//  ILightBulb.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 18.02.2022.
//

#pragma once

#include <memory>

class ILightBulb
{
public:
    virtual ~ILightBulb() = default;
    virtual void On() = 0;
    virtual void Off() = 0;

    virtual std::unique_ptr<ILightBulb> clone() const = 0;
};

