//
//  main.cpp
//  RoadNetworkInfrastructure
// Patterns:
// Builder, Bridge, decorator, state, pool TrafficLights
//
//  Created by Andrew Borisov on 18.02.2022.
//

#include <iostream>

#include <memory>
#include <vector>
#include <list>

#include "src/ILightBulb.h"
#include "src/LightBulb.h"
#include "src/CrossRoads.h"
#include "src/Bridge.h"
#include "src/ITrafficLight.h"
#include "src/TrafficLight.h"
#include "src/DoubleTrafficLight.h"
#include "src/TripleTrafficLight.h"
#include "src/ITrafficLightsController.h"
#include "src/TrafficLightsController.h"
#include "src/ControllerStateMachine.h"
#include "src/ControllerLogicModule.h"
#include "src/TrafficLightsTimingController.h"
#include "src/ITrafficLightsTimingController.h"

// Light bulb
std::vector<ColorLightBulb> vLightBulbs{ColorLightBulb::RED, ColorLightBulb::GREEN};

std::vector<std::unique_ptr<ILightBulb>> createLightBulbs(const std::vector<ColorLightBulb>& vfLightBulbs) {
    
    std::vector<std::unique_ptr<ILightBulb>> vLightBulbs;
    
    for(const ColorLightBulb& color : vfLightBulbs) {
        vLightBulbs.emplace_back(std::make_unique<LightBulb>(color));
    }
    return vLightBulbs;
}

std::vector<TypeTrafficLight> vTrafficLights{TypeTrafficLight::DOUBLE_TRANS, TypeTrafficLight::DOUBLE_PEOPLE};

std::unique_ptr<ITrafficLight> createTrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>> lightBulbs) {

    return std::make_unique<TrafficLight>();
}

std::unique_ptr<ITrafficLight> createDoubleTrafficLight() {
    std::unique_ptr<DoubleTrafficLight> doubleTrafficLight = std::make_unique<DoubleTrafficLight>();
    std::vector<ColorLightBulb> colorsLightBulbs{ColorLightBulb::GREEN, ColorLightBulb::RED};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs = createLightBulbs(colorsLightBulbs);
    doubleTrafficLight->init(TypeTrafficLight::DOUBLE_TRANS, std::move(lightBulbs));
    return doubleTrafficLight;
}

std::unique_ptr<ControllerStateMachine> createControllerStateMachine() {
    return std::make_unique<ControllerStateMachine>();
}

std::unique_ptr<ITrafficLightsTimingController> createTrafficLightsTimingController() {
    return std::make_unique<TrafficLightsTimingController>();
}

std::unique_ptr<CrossRoads> createCrossroad() {
    return std::make_unique<CrossRoads>();
}

//---------------- Builder -----------------

// Class road object contains all road objects type
class RoadInfrastructure {
public:
    RoadInfrastructure(){};
    std::vector<std::unique_ptr<ITrafficLight>> tL;
    std::vector<std::unique_ptr<ITrafficLightsController>> tLC;
    std::vector<std::unique_ptr<Bridge>> br;
    std::vector<std::unique_ptr<ICrossRoads>> cR;
};

class RoadInfrastructureBuilder {
protected:
    std::unique_ptr<RoadInfrastructure> roadInfrastructure;
public:
    RoadInfrastructureBuilder(): roadInfrastructure{nullptr} {}
    virtual ~RoadInfrastructureBuilder(){}
    virtual void createRoadInfrastructureBuilder(){}
    virtual void buildTrafficLightsController(){}
    virtual void buildTrafficLight(){}
    virtual void buildCrossRoads(){}
    virtual void buildBridge(){}
    virtual std::unique_ptr<RoadInfrastructure> getRoadInfrastructure() { return std::make_unique<RoadInfrastructure>(); }
};

// Simple cars crossRoads
class TransportRoadInfrastructureBuilder: public RoadInfrastructureBuilder {
public:
    void createRoadInfrastructureBuilder() { roadInfrastructure = std::make_unique<RoadInfrastructure>(); }
    void buildTrafficLightsController(){roadInfrastructure->tLC.emplace_back(std::make_unique<TrafficLightsController>()); }
    void buildTrafficLight(){roadInfrastructure->tL.emplace_back(std::make_unique<TrafficLight>()); }
    void buildCrossRoads(){roadInfrastructure->cR.emplace_back(std::make_unique<CrossRoads>()); }
};

// People cars crossRoads with bride for people across the street
class PeopleTransportRoadInfrastructureBuilder: public RoadInfrastructureBuilder {
public:
    void createRoadInfrastructureBuilder() { roadInfrastructure = std::make_unique<RoadInfrastructure>(); }
    void buildCrossRoads(){roadInfrastructure->cR.emplace_back(std::make_unique<CrossRoads>()); }
    void buildBridge(){roadInfrastructure->br.emplace_back(std::make_unique<Bridge>()); }
};

class Director {
public:
    std::unique_ptr<RoadInfrastructure> createRoadInfrastructure(RoadInfrastructureBuilder& builder) {
        builder.createRoadInfrastructureBuilder();
        builder.buildTrafficLight();
        builder.buildTrafficLightsController();
        builder.buildBridge();
        builder.buildCrossRoads();
        return (builder.getRoadInfrastructure());
    }
};

//-------------- TrafficLights Pool -------------------------------

class TrafficLightPool {
    public:
       TrafficLightPool() {}

       static TrafficLightPool* getInstance() {
           if (instance == nullptr) {
                instance = new TrafficLightPool();
           }
           return instance;
       }

       std::unique_ptr<ITrafficLight> getTrafficLight() {
           if (m_trafficLights.empty()) {
               std::cout << "TrafficLight created" << '\n';
               return std::make_unique<TrafficLight>();
           } 
           else 
           { 
                std::unique_ptr<ITrafficLight> trafficLight = std::move(m_trafficLights.front());
                m_trafficLights.pop_front();
                return trafficLight;
           }
       }

       void returnTrafficLight(std::unique_ptr<ITrafficLight> trafficLight) {
           m_trafficLights.push_back(std::move(trafficLight));
        }

    private:
       std::list<std::unique_ptr<ITrafficLight>> m_trafficLights;

       static TrafficLightPool* instance;
};

TrafficLightPool* TrafficLightPool::instance = 0;

//-------------- TrafficLight Decorator -------------------------------
class Decorator : public TrafficLight {
    public:
        Decorator(std::unique_ptr<ITrafficLight> trL) : trL_{std::move(trL)} {

        }
        
        virtual ~Decorator() = default;

        virtual void allow() override {
            trL_->allow();
        }
        virtual void disallow() override {
            trL_->disallow();
        }

    protected:
        std::unique_ptr<ITrafficLight> trL_;
};

class DoubleTrafficLightDecorator : public Decorator {
    public:
        DoubleTrafficLightDecorator(std::unique_ptr<ITrafficLight> trL) : Decorator{std::move(trL)} {

        }

        virtual ~DoubleTrafficLightDecorator() = default;

        virtual void allow() override {
            Decorator::allow();
            
            TrafficLight* trafficLight = dynamic_cast<TrafficLight*>(trL_.get());
            if(trafficLight){
                const std::vector<std::unique_ptr<ILightBulb>>& bulbs = trafficLight->getBulb();
                if(bulbs.size() >= 1) {
                   bulbs.at(static_cast<int>(ColorLightBulb::RED))->Off();
                }
            }
        }

        virtual void disallow() override {
            Decorator::disallow();

            TrafficLight* trafficLight = dynamic_cast<TrafficLight*>(trL_.get());
            if(trafficLight){
                const std::vector<std::unique_ptr<ILightBulb>>& bulbs = trafficLight->getBulb();
                if(bulbs.size() >= 1) {
                       bulbs.at(static_cast<int>(ColorLightBulb::RED))->On();
                }
            }
        }
};

class TripleTrafficLightDecorator : public Decorator {
    public:
        TripleTrafficLightDecorator(std::unique_ptr<ITrafficLight> trL) : Decorator(std::move(trL)) {
            
        }

        virtual void allow() override {
            Decorator::allow();
            waitOff();
        }

        virtual void disallow() override {
            Decorator::disallow();
            waitOff();
        }

        void waitOn() {
            Decorator::disallow();
             
            //auto doubleTrafficLight = std::dynamic_pointer_cast<DoubleTrafficLight>(trL_);

            /*DoubleTrafficLight* doubleTrafficLight = dynamic_cast<DoubleTrafficLight*>(trL_);
            if(doubleTrafficLight) {
                const std::vector<std::unique_ptr<ILightBulb>>& bulbs = doubleTrafficLight->getBulb();
                if(bulbs.size() >= 3) {
                    bulbs.at(static_cast<int>(ColorLightBulb::YELLOW))->On();
                }
            }*/
        }

        void waitOff() {
            /*DoubleTrafficLight* doubleTrafficLight = dynamic_cast<DoubleTrafficLight*>(trL_);
            if(doubleTrafficLight) {
                const std::vector<std::unique_ptr<ILightBulb>>& bulbs = doubleTrafficLight->getBulb();
                if(bulbs.size() >= 3) {
                    bulbs.at(static_cast<int>(ColorLightBulb::YELLOW))->Off();
                }
            }*/
        }
};

std::unique_ptr<ITrafficLight> createTripleTafficLight() {
    //Create double traffic light
    std::unique_ptr<DoubleTrafficLight> doubleTrafficLight = std::make_unique<DoubleTrafficLight>();
    std::vector<ColorLightBulb> colorsLightBulbs{ColorLightBulb::GREEN, ColorLightBulb::RED};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs = createLightBulbs(colorsLightBulbs);
    doubleTrafficLight->init(TypeTrafficLight::DOUBLE_TRANS, std::move(lightBulbs));

    doubleTrafficLight->addBulb(std::make_unique<LightBulb>(ColorLightBulb::YELLOW));
    //std::unique_ptr<TripleTrafficLightDecorator> tripleTrafficLight = std::make_unique<TripleTrafficLightDecorator>(doubleTrafficLight.release());
    std::unique_ptr<TripleTrafficLightDecorator> tripleTrafficLight = std::make_unique<TripleTrafficLightDecorator>(std::move(doubleTrafficLight));
    return tripleTrafficLight;
}

std::unique_ptr<ITrafficLight> createTripleTrafficLightDecorator() {
    std::vector<ColorLightBulb> colorsLightBulbs{ColorLightBulb::GREEN, ColorLightBulb::RED, ColorLightBulb::YELLOW};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs = createLightBulbs(colorsLightBulbs);
    /*std::unique_ptr<ITrafficLight> tripleTrafficLightDecorator = std::make_unique<DoubleTrafficLightDecorator>(
                                                                     std::make_unique<TripleTrafficLightDecorator>(
                                                                        std::make_unique<TrafficLight>(std::move(lightBulbs))));*/

    std::unique_ptr<ITrafficLight> tripleTrafficLightDecorator = std::make_unique<DoubleTrafficLightDecorator>(
                                                                     std::make_unique<TrafficLight>(std::move(lightBulbs)));
    return tripleTrafficLightDecorator;
}

int main(int argc, const char* argv[]) {
    /*std::vector<std::unique_ptr<ILightBulb>> vBulbs(createLightBulbs(vLightBulbs));
    std::unique_ptr<ITrafficLight> mainTrafficLight = createTrafficLight(TypeTrafficLight::DOUBLE_TRANS, vBulbs);
    std::unique_ptr<ControllerStateMachine> mainControllerStateMachine(std::move(createControllerStateMachine()));
    std::unique_ptr<ITrafficLightsTimingController> mainTrafficLightTimingController(std::move(createTrafficLightsTimingController()));*/

    /*Director director;
    TransportRoadInfrastructureBuilder tRi_builder;
    PeopleTransportRoadInfrastructureBuilder pTrI_builder;
    std::unique_ptr<RoadInfrastructure> tRinfrastructure= director.createRoadInfrastructure(tRi_builder);
    std::unique_ptr<RoadInfrastructure> pTrInfrastructure = director.createRoadInfrastructure(pTrI_builder);*/
    
    std::cout << "Hello road!" << std::endl;

    /*while(true) {
        if(mainTrafficLightTimingController)
            mainTrafficLightTimingController->update();
    }*/

    // Create double traffic light (DONE)
    /*std::unique_ptr<ITrafficLight> doubleTrafficLight = createDoubleTrafficLight();
    doubleTrafficLight->allow();
    doubleTrafficLight->disallow();*/

    // Create triple traffic light (DONE)
    /*std::unique_ptr<ITrafficLight> tripleTrafficLight = createTripleTafficLight();
    tripleTrafficLight->allow();*/
    //tripleTrafficLight->disallow();
    /*if(dynamic_cast<TripleTrafficLightDecorator*>(tripleTrafficLight.get())) {
        dynamic_cast<TripleTrafficLightDecorator*>(tripleTrafficLight.get())->waitOn();
    }*/

    // Create triple traffic light decorator
    std::unique_ptr<ITrafficLight> tripleTrafficLightDecorator = createTripleTrafficLightDecorator();
    tripleTrafficLightDecorator->disallow();

    // Pool of TrafficLights
    /*TrafficLightPool* pool = TrafficLightPool::getInstance();
    std::unique_ptr<ITrafficLight> trafficLight1;
    std::unique_ptr<ITrafficLight> trafficLight2;*/
    /* Resource will be created */
    /*trafficLight1 = pool->getTrafficLight();
    std::vector<ColorLightBulb> colorsLightBulbs1{ColorLightBulb::GREEN, ColorLightBulb::RED};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs1 = createLightBulbs(colorsLightBulbs1);
    static_cast<TrafficLight*>(trafficLight1.get())->init(TypeTrafficLight::DOUBLE_TRANS, std::move(lightBulbs1));
    trafficLight1->allow();
    trafficLight1->disallow();

    trafficLight2 = pool->getTrafficLight();
    std::vector<ColorLightBulb> colorsLightBulbs2{ColorLightBulb::GREEN, ColorLightBulb::RED, ColorLightBulb::YELLOW};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs2 = createLightBulbs(colorsLightBulbs2);
    static_cast<TrafficLight*>(trafficLight2.get())->init(TypeTrafficLight::TRIPLE_TRANS, std::move(lightBulbs2));
    trafficLight2->allow();
    trafficLight2->disallow();*/

    return 0;
}
