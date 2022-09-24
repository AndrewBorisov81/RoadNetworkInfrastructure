//
//  TrafficLight.cpp
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 20.02.2022.
//

#include <stdio.h>

#include "TrafficLight.h"
#include "TrafficLightImpl.h"
#include "ILightBulb.h"

#include <iostream>

TrafficLight::TrafficLight() {
    
}

TrafficLight:: TrafficLight(std::unique_ptr<TrafficLightImpl> p) : m_pimpl{std::move(p)} {

}

TrafficLight::~TrafficLight() {
   
}

void TrafficLight::init(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {
    
}

void TrafficLight::allow() {
   if(m_vBulbs.at(0))
      m_vBulbs.at(0)->On();

   std::cout << "Allow TrafficLight" << '\n';
}

void TrafficLight::disallow() {
    if(m_vBulbs.at(0))
       m_vBulbs.at(0)->Off();

   std::cout << "Disallow TrafficLight" << "\n";
}

TypeTrafficLight TrafficLight::getType() const {
   return m_type;
}
