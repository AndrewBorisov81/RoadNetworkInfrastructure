#include "TrafficLightImpl.h"
#include "LightBulb.h"

#include <iostream>
#include <vector>

TrafficLightImpl::~TrafficLightImpl() {

}

void TripleTrafficLightImpl::triple_allow(const std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {

    if(lightBulbs.size() >= 2) {
        lightBulbs.at(static_cast<int>(ColorLightBulb::GREEN))->On();
        lightBulbs.at(static_cast<int>(ColorLightBulb::RED))->Off();
    }

    if(lightBulbs.size() == 3) {
        lightBulbs.at(static_cast<int>(ColorLightBulb::YELLOW))->Off();
    }

    std::cout << "Triple trafficLight triple_allow" << "\n";
}

void TripleTrafficLightImpl::triple_disallow(const std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {
    if(lightBulbs.size() >= 2) {
        lightBulbs.at(static_cast<int>(ColorLightBulb::GREEN))->Off();
        lightBulbs.at(static_cast<int>(ColorLightBulb::RED))->On();
    }
  
    if(lightBulbs.size() == 3) {
        lightBulbs.at(static_cast<int>(ColorLightBulb::YELLOW))->Off();
    }

    std::cout << "Triple trafficLight triple_disallow" << "\n";
}


void TripleTrafficLightImpl::wait(const std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {
    if(lightBulbs.size() >= 2) {
        lightBulbs.at(static_cast<int>(ColorLightBulb::GREEN))->Off();
        lightBulbs.at(static_cast<int>(ColorLightBulb::RED))->Off();
    }
  
    if(lightBulbs.size() == 3) {
        lightBulbs.at(static_cast<int>(ColorLightBulb::YELLOW))->On();
    }

    std::cout << "Triple trafficLight wait" << "\n";
}
