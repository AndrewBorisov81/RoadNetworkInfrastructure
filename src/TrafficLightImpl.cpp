#include "TrafficLightImpl.h"

#include <iostream>

void DoubleTrafficLightImpl::double_allow() {
    std::cout << "Double trafficLight allow" << "\n";
}

void DoubleTrafficLightImpl::double_disallow() {
    std::cout << "Double trafficLight disallow" << "\n";
}

void TripleTrafficLightImpl::triple_allow() {
    std::cout << "Triple trafficLight allow" << "\n";
}

void TripleTrafficLightImpl::triple_disallow() {
    std::cout << "Triple traffciLigt disallow" << "\n";
}
