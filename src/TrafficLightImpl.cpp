#include "TrafficLightImpl.h"

#include <iostream>

TrafficLightImpl::~TrafficLightImpl() {

}

void TrafficLightImpl::double_allow() {

}

void TrafficLightImpl::double_disallow() {

}

void TrafficLightImpl::triple_allow() {

}

void TrafficLightImpl::triple_disallow() {

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


