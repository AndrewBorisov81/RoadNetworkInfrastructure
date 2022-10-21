#include "DoubleTrafficLight.h"
#include "LightBulb.h"

DoubleTrafficLight::DoubleTrafficLight(const DoubleTrafficLight& other) : TrafficLight(other){

}

std::unique_ptr<ITrafficLight> DoubleTrafficLight::clone() const {
    return std::make_unique<DoubleTrafficLight>();
}

void DoubleTrafficLight::allow() {   
    TrafficLight::allow();
    
    if(m_vBulbs.at(1))
       m_vBulbs.at(1)->Off();

   std::cout << "Allow DoubleTrafficLight" << '\n';
}

void DoubleTrafficLight::disallow() {
    TrafficLight::disallow();
    
    if(m_vBulbs.at(1))
        m_vBulbs.at(1)->On();

   std::cout << "Disallow DoubleTrafficLight" << "\n";
}

