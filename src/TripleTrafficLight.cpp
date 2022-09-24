#include "TripleTrafficLight.h"
#include "TrafficLightImpl.h"

TripleTrafficLight::TripleTrafficLight() : TrafficLight{std::make_unique<TripleTrafficLightImpl>()} {

}

TripleTrafficLight::~TripleTrafficLight() {

}

void TripleTrafficLight::allow() {
    m_pimpl->triple_allow();
}

void TripleTrafficLight::disallow() {
    m_pimpl->triple_disallow();
}
