#include "TrafficLightImpl.h"
#include "ILightBulb.h"

#include <iostream>
#include <vector>

TrafficLightImpl::~TrafficLightImpl() {

}

void TripleTrafficLightImpl::triple_allow(std::vector<std::unique_ptr<ILightBulb>> lightBulbs) {
    if(lightBulbs.size() == 3) {
        std::unique_ptr<ILightBulb> yellowlightBulb{std::move(lightBulbs.at(2))};
        yellowlightBulb->On();
    }
    std::cout << "Triple trafficLight triple_allow" << "\n";
}

void TripleTrafficLightImpl::triple_disallow(std::vector<std::unique_ptr<ILightBulb>> lightBulbs) {
     if(lightBulbs.size() == 3) {
        std::unique_ptr<ILightBulb> yellowlightBulb{std::move(lightBulbs.at(2))};
        yellowlightBulb->Off();
    }
    std::cout << "Triple trafficLight triple_disallow" << "\n";
}
