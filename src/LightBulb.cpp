#include "LightBulb.h"

LightBulb::LightBulb(ColorLightBulb color) : m_color{color} {
    
}

void LightBulb::On() { 
    std::cout << m_colors[static_cast<int>(m_color)] << " LightBulb On!" << '\n'; 
}

void LightBulb::Off() { 
    std::cout << m_colors[static_cast<int>(m_color)] << " LightBulb Off!" << '\n'; 
}

std::shared_ptr<ILightBulb> LightBulb::clone() const {
    return cloneImplementation();
}

std::shared_ptr<ILightBulb> LightBulb::cloneImplementation() const {
    return std::shared_ptr<LightBulb>(new LightBulb(*this));
}
