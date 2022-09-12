#include "TrafficLightImpl.h"

#include <iostream>

TrafficLightImpl::~TrafficLightImpl() {

}

void DoubleTrafficLightImpl::allow() {
    std::cout << "Double trafficLight allow" << "\n";
}

void DoubleTrafficLightImpl::disallow() {
    std::cout << "Double trafficLight disallow" << "\n";
}

void DoubleTrafficLightImpl::double_allow() {
    std::cout << "Double trafficLight double_allow" << "\n";
}

void DoubleTrafficLightImpl::double_disallow() {
    std::cout << "Double trafficLight double_disallow" << "\n";
}

void DoubleTrafficLightImpl::triple_allow() {
    std::cout << "Double trafficLight triple_disallow" << "\n";
}

void DoubleTrafficLightImpl::triple_disallow() {
    std::cout << "Double trafficLight triple_disallow" << "\n";
}

void TripleTrafficLightImpl::allow() {
    std::cout << "Triple trafficLight allow" << "\n";
}


void TripleTrafficLightImpl::disallow() {
    std::cout << "Triple trafficLight disallow" << "\n";
}

void TripleTrafficLightImpl::double_allow() {
    std::cout << "Triple trafficLight doble_allow" << "\n";
}

void TripleTrafficLightImpl::double_disallow() {
    std::cout << "Triple trafficLight doble_disallow" << "\n";
}

void TripleTrafficLightImpl::triple_allow() {
    std::cout << "Triple trafficLight triple_allow" << "\n";
}

void TripleTrafficLightImpl::triple_disallow() {
    std::cout << "Triple trafficLight triple_disallow" << "\n";
}
