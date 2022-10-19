//
//  TrafficLight.h
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 19.02.2022.
//

#pragma once

#include <memory>
#include <vector>

#include "ITrafficLight.h"

class ILightBulb;

enum class TypeTrafficLight { NONE, DOUBLE_PEOPLE, TRIPLE_PEOPLE, DOUBLE_TRANS, TRIPLE_TRANS };

class TrafficLight: public ITrafficLight
{
    public:
        TrafficLight();
        virtual ~TrafficLight();
    
        virtual void allow() override;
        virtual void disallow() override;

        void init(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>> lightBulbs);

        TypeTrafficLight getType() const;

        TrafficLight(const TrafficLight& other);
        
        std::unique_ptr<ITrafficLight> clone() const override;

    protected:
        std::vector<std::unique_ptr<ILightBulb>> m_vBulbs;
        TypeTrafficLight m_type{TypeTrafficLight::DOUBLE_TRANS};
};
