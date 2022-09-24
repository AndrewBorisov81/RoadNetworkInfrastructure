#pragma once

class TrafficLightImpl {
    public:
        virtual ~TrafficLightImpl();
        virtual void double_allow() = 0;
        virtual void double_disallow() = 0;
        virtual void triple_allow() = 0;
        virtual void triple_disallow() = 0;
};

class TripleTrafficLightImpl : public TrafficLightImpl {
    public:
        virtual void double_allow();
        virtual void double_disallow();
        virtual void triple_allow();
        virtual void triple_disallow();
};
