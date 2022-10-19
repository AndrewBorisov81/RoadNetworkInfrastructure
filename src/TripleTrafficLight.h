#pragma once

#include "TrafficLight.h"

#include <memory>

class TripleTrafficLight: public TrafficLight {
    public:
        TripleTrafficLight();
        virtual ~TripleTrafficLight();

        TripleTrafficLight(const TripleTrafficLight& other);

        std::unique_ptr<ITrafficLight> clone() const override;

        void virtual allow() override;
        void virtual disallow() override;

        void wait();
};
