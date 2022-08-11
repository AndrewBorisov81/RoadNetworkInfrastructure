//
//  LightBulb.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 18.02.2022.
//

#pragma once
#include "ILightBulb.h"

enum class ColorLightBulb { NONE, RED, GREEN, YELLOW };

class LightBulb : public ILightBulb
{
public:
    LightBulb() {}
    LightBulb(ColorLightBulb color) : m_color{color} {}
    virtual ~LightBulb() override = default;
    
    virtual void On() override {}
    virtual void Off() override {}
private:
    ColorLightBulb m_color {ColorLightBulb::NONE};
};
