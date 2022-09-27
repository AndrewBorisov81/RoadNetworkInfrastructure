#include "LightBulb.h"

LightBulb::LightBulb() {

}

LightBulb::LightBulb(ColorLightBulb color) : m_color{color} {
    
}

LightBulb::~LightBulb() {

}

void LightBulb::On() { 
    std::cout << m_colors[static_cast<int>(m_color)] << " LightBulb On!" << '\n'; 
}

void LightBulb::Off() { 
    std::cout << m_colors[static_cast<int>(m_color)] << " LightBulb Off!" << '\n'; 
}

std::unique_ptr<ILightBulb> LightBulb::clone() const {
    return std::make_unique<LightBulb>(*this);
}
