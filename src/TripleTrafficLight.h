#pragma once

#include "TrafficLight.h"

class TripleTrafficLight: public TrafficLight {
    public:
        TripleTrafficLight();
        virtual ~ TripleTrafficLight();

        void virtual allow() override;
        void virtual disallow() override;
};
