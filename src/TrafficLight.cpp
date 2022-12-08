//
//  TrafficLight.cpp
//  RoadNetworkInfrastructure
//
//  Created by Andrew Borisov on 20.02.2022.
//
#include "TrafficLight.h"

#include <iostream>

TrafficLight::TrafficLight(std::vector<std::shared_ptr<ILightBulb>> lightBulbs) {
    m_vBulbs.reserve(lightBulbs.size());
    for(const auto& b: lightBulbs) {
      m_vBulbs.push_back(b->clone());
    }
}

TrafficLight::TrafficLight(const TrafficLight& other) {
   m_type = other.m_type;
   m_vBulbs.reserve(other.m_vBulbs.size());
    for(const auto& b: other.m_vBulbs) {
      m_vBulbs.push_back(b->clone());
    }
}

void TrafficLight::init(TypeTrafficLight typeTrafficLight, std::vector<std::shared_ptr<ILightBulb>> lightBulbs) {
    m_type = typeTrafficLight;
    m_vBulbs.reserve(lightBulbs.size());
    for(const auto& b: lightBulbs) {
      m_vBulbs.push_back(b->clone());
    }
}

void TrafficLight::allow() {
   if(m_vBulbs.size() > 0) {
       m_vBulbs.at(static_cast<int>(ColorLightBulb::GREEN))->On();
   }

   std::cout << "Allow TrafficLight" << '\n';
}

void TrafficLight::disallow() {
   if(m_vBulbs.size() > 0) {
      m_vBulbs.at(static_cast<int>(ColorLightBulb::GREEN))->Off();
   }

   std::cout << "Disallow TrafficLight" << "\n";
}

TypeTrafficLight TrafficLight::getType() const {
   return m_type;
}

std::unique_ptr<ITrafficLight> TrafficLight::clone() const {
    return std::make_unique<TrafficLight>(*this);
}

void TrafficLight::addBulb(std::shared_ptr<ILightBulb> lightBulb) {
   m_vBulbs.push_back(std::move(lightBulb));
}

const std::vector<std::shared_ptr<ILightBulb>>& TrafficLight::getBulbs() const {
   return m_vBulbs;
}
