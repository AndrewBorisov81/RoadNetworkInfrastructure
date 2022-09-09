#pragma once

#include "TrafficLight.h"

class DoubleTrafficLight : public TrafficLight {
    public:
        DoubleTrafficLight();
        virtual ~DoubleTrafficLight();

        virtual void allow() override;
        virtual void disallow() override;
};
