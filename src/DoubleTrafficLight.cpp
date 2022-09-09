#include "DoubleTrafficLight.h"
#include "TrafficLightImpl.h"

DoubleTrafficLight::DoubleTrafficLight() : TrafficLight(new DoubleTrafficLightImpl()) {

}

DoubleTrafficLight::~DoubleTrafficLight() {

}

void DoubleTrafficLight::allow() {
    pimpl->double_allow();
}

void DoubleTrafficLight::disallow() {
    pimpl->double_disallow();
}



