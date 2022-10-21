#pragma once

#include "TrafficLight.h"

class DoubleTrafficLight : public TrafficLight {
    public:
        virtual ~DoubleTrafficLight() = default;
        DoubleTrafficLight() = default;
        DoubleTrafficLight(const DoubleTrafficLight& other);

        virtual void allow() override;
        virtual void disallow() override;

        virtual std::unique_ptr<ITrafficLight> clone() const override;
};
