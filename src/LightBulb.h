//
//  LightBulb.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 18.02.2022.
//

#pragma once

#include "ILightBulb.h"

#include <iostream>

enum class ColorLightBulb { NONE, RED, GREEN, YELLOW };

class LightBulb : public ILightBulb
{
public:
    LightBulb() {}
    LightBulb(ColorLightBulb color) : m_color{color} {}
    virtual ~LightBulb() override = default;
    
    virtual void On() override { std::cout << "LightBulb On!" << '\n'; }
    virtual void Off() override { std::cout << "LightBulb Off!" << '\n'; }
private:
    ColorLightBulb m_color {ColorLightBulb::NONE};
};
