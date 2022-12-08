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

enum class ColorLightBulb {GREEN, RED, YELLOW };

class LightBulb : public ILightBulb
{
public:
    LightBulb(ColorLightBulb color);
    virtual ~LightBulb() = default;
    LightBulb() = default;
    LightBulb(const LightBulb&) = default;
    LightBulb(LightBulb&&) = delete;
    LightBulb& operator=(const LightBulb&) = delete;
    LightBulb& operator=(LightBulb&&) = delete;

    virtual std::shared_ptr<ILightBulb> clone() const override;
    virtual void On() override;
    virtual void Off() override;
private:
    virtual std::shared_ptr<ILightBulb> cloneImplementation() const;

    ColorLightBulb m_color {ColorLightBulb::GREEN};
    std::vector<std::string> m_colors{"Green", "Red", "Yellow"};
};

