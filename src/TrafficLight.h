//
//  TrafficLight.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 19.02.2022.
//

#pragma once
#include <vector>

#include "ITrafficLight.h"

class ILightBulb;

enum class TypeTrafficLight { NONE, DOUBLE_PEOPLE, TRIPLE_PEOPLE, DOUBLE_TRANS, TRIPLE_TRANS };

class TrafficLight: public ITrafficLight
{
public:
    TrafficLight();
    TrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs);
    virtual ~TrafficLight() = default;
    
    virtual void init() override;
    virtual void allow() override;
    virtual void disallow() override;

    TypeTrafficLight getType() const;
    
private:
    std::vector<std::unique_ptr<ILightBulb>> m_vBulbs;
    TypeTrafficLight m_type{TypeTrafficLight::DOUBLE_TRANS};
};
