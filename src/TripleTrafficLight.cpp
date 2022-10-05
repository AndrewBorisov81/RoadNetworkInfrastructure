#include "TripleTrafficLight.h"
#include "TrafficLightImpl.h"
#include "LightBulb.h"

#include <vector>
#include <memory>

TripleTrafficLight::TripleTrafficLight() : TrafficLight{std::make_unique<TripleTrafficLightImpl>()} {

}

TripleTrafficLight::~TripleTrafficLight() {

}

void TripleTrafficLight::allow() {
    m_pimpl->triple_allow(std::move(m_vBulbs));
}

void TripleTrafficLight::disallow() {
    m_pimpl->triple_disallow(std::move(m_vBulbs));
}
