#include "TripleTrafficLight.h"

TripleTrafficLight::TripleTrafficLight() {

}

TripleTrafficLight::~TripleTrafficLight() {

}

TripleTrafficLight::TripleTrafficLight(const TripleTrafficLight& other) {
    bool stop = true;
}

std::unique_ptr<ITrafficLight> TripleTrafficLight::clone() const {
    std::make_unique<TripleTrafficLight>(*this);
}

void TripleTrafficLight::allow() {

}

void TripleTrafficLight::disallow() {

}

void TripleTrafficLight::wait() {

}
