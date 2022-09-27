//
//  LightBulb.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 18.02.2022.
//

#pragma once

#include "ILightBulb.h"

#include <iostream>
#include <string>
#include <vector>

enum class ColorLightBulb { NONE, RED, GREEN, YELLOW };

class LightBulb : public ILightBulb
{
public:
    LightBulb();
    LightBulb(ColorLightBulb color);
    virtual ~LightBulb() override;

    virtual std::unique_ptr<ILightBulb> clone() const override;
    virtual void On() override;
    virtual void Off() override;
private:
    ColorLightBulb m_color {ColorLightBulb::NONE};
    std::vector<std::string> m_colors{"None", "Red", "Green", "Yellow"};
};
