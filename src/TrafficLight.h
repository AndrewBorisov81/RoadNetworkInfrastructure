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
#include "LightBulb.h"

enum class TypeTrafficLight { NONE, DOUBLE_PEOPLE, TRIPLE_PEOPLE, DOUBLE_TRANS, TRIPLE_TRANS };

class TrafficLight: public ITrafficLight
{
    public:
        std::unique_ptr<ITrafficLight> clone() const override;
        TrafficLight() = default;
        TrafficLight(std::vector<std::shared_ptr<ILightBulb>> lightBulbs);
        virtual ~TrafficLight() = default;
        TrafficLight(const TrafficLight&);
        TrafficLight(const TrafficLight&&) = delete;
        TrafficLight& operator=(const TrafficLight&) = delete;
        TrafficLight& operator=(const TrafficLight&&) = delete;
    
        virtual void allow() override;
        virtual void disallow() override;

        void init(TypeTrafficLight typeTrafficLight, std::vector<std::shared_ptr<ILightBulb>> lightBulbs);

        void addBulb(std::shared_ptr<ILightBulb> lightBulb);

        const std::vector<std::shared_ptr<ILightBulb>>& getBulbs() const;

        TypeTrafficLight getType() const;
    protected:
        std::vector<std::shared_ptr<ILightBulb>> m_vBulbs;
        TypeTrafficLight m_type{TypeTrafficLight::DOUBLE_TRANS};
};
