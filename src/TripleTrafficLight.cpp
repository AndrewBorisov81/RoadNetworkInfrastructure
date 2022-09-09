#include "TripleTrafficLight.h"
#include "TrafficLightImpl.h"

TripleTrafficLight::TripleTrafficLight() : TrafficLight{new TripleTrafficLightImpl()} {

}

TripleTrafficLight::~TripleTrafficLight() {

}

void TripleTrafficLight::allow() {
pimpl->triple_allow();
}

void TripleTrafficLight::disallow() {
pimpl->triple_disallow();
}

