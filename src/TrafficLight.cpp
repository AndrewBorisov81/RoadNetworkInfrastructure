//
//  TrafficLight.cpp
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 20.02.2022.
//

#include <stdio.h>

#include "TrafficLight.h"
#include "ILightBulb.h"

#include <memory>

TrafficLight::TrafficLight() {
    
}

TrafficLight::TrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs)
 : m_type{typeTrafficLight}, m_vBulbs(std::move(lightBulbs)) {

}

void TrafficLight::init() {
    
}

void TrafficLight::allow() {
   if(m_vBulbs.at(0))
      m_vBulbs.at(0)->On();
    
    if(m_vBulbs.at(1))
       m_vBulbs.at(1)->Off();
}

void TrafficLight::disallow() {
    if(m_vBulbs.at(0))
       m_vBulbs.at(0)->Off();
    
   if(m_vBulbs.at(1))
      m_vBulbs.at(1)->On();
}

TypeTrafficLight TrafficLight::getType() const {
   return m_type;
}