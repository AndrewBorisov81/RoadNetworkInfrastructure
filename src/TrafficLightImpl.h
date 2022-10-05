#pragma once

#include <memory>

class ILightBulb;

class TrafficLightImpl {
    public:
        virtual ~TrafficLightImpl();
        virtual void triple_allow(std::vector<std::unique_ptr<ILightBulb>> lightBulbs) = 0;
        virtual void triple_disallow(std::vector<std::unique_ptr<ILightBulb>> lightBulbs) = 0;
};

class TripleTrafficLightImpl : public TrafficLightImpl {
    public:
        virtual void triple_allow(std::vector<std::unique_ptr<ILightBulb>> lightBulbs) override;
        virtual void triple_disallow(std::vector<std::unique_ptr<ILightBulb>> lightBulbs) override;
};
