//
//  main.cpp
//  RoadNetworkInfrastructure
// Patterns:
// Bridge, decorator, state
//
//  Created by Andrew Borisov on 18.02.2022.
//

#include <iostream>

#include <memory>
#include <vector>

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

std::unique_ptr<ITrafficLight> createTrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {

    return std::make_unique<TrafficLight>();
}

std::unique_ptr<ITrafficLight> createDoubleTrafficLight() {
    std::unique_ptr<DoubleTrafficLight> doubleTrafficLight = std::make_unique<DoubleTrafficLight>();
    std::vector<ColorLightBulb> colorsLightBulbs{ColorLightBulb::GREEN, ColorLightBulb::RED};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs = createLightBulbs(colorsLightBulbs);
    TypeTrafficLight typeTrafficLight{TypeTrafficLight::DOUBLE_TRANS};
    doubleTrafficLight->init(typeTrafficLight, std::move(lightBulbs));
    return doubleTrafficLight;
}

std::unique_ptr<ITrafficLight> createTripleTafficLight() {
    std::unique_ptr<TripleTrafficLight> tripleTrafficLight = std::make_unique<TripleTrafficLight>();
    std::vector<ColorLightBulb> colorsLightBulbs{ColorLightBulb::GREEN, ColorLightBulb::RED, ColorLightBulb::YELLOW};
    std::vector<std::unique_ptr<ILightBulb>> lightBulbs = createLightBulbs(colorsLightBulbs);
    TypeTrafficLight typeTrafficLight{TypeTrafficLight::TRIPLE_TRANS};
    tripleTrafficLight->init(typeTrafficLight, std::move(lightBulbs));
    return tripleTrafficLight;
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

// Class road object contains all road objects type
class RoadInfrastructure {
public:
    RoadInfrastructure(){};
    std::vector<std::unique_ptr<ITrafficLight>> tL;
    std::vector<std::unique_ptr<ITrafficLightsController>> tLC;
    std::vector<std::unique_ptr<Bridge>> br;
    std::vector<std::unique_ptr<ICrossRoads>> cR;
};

// Builder
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

// simple cars crossRoads
class TransportRoadInfrastructureBuilder: public RoadInfrastructureBuilder {
public:
    void createRoadInfrastructureBuilder() { roadInfrastructure = std::make_unique<RoadInfrastructure>(); }
    void buildTrafficLightsController(){roadInfrastructure->tLC.emplace_back(std::make_unique<TrafficLightsController>()); }
    void buildTrafficLight(){roadInfrastructure->tL.emplace_back(std::make_unique<TrafficLight>()); }
    void buildCrossRoads(){roadInfrastructure->cR.emplace_back(std::make_unique<CrossRoads>()); }
};

// people cars crossRoads with bride for people across the street
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

int main(int argc, const char* argv[]) {
    /*std::vector<std::unique_ptr<ILightBulb>> vBulbs(createLightBulbs(vLightBulbs));
    std::unique_ptr<ITrafficLight> mainTrafficLight = createTrafficLight(TypeTrafficLight::DOUBLE_TRANS, vBulbs);
    std::unique_ptr<ControllerStateMachine> mainControllerStateMachine(std::move(createControllerStateMachine()));
    std::unique_ptr<ITrafficLightsTimingController> mainTrafficLightTimingController(std::move(createTrafficLightsTimingController()));*/

    Director director;
    TransportRoadInfrastructureBuilder tRi_builder;
    PeopleTransportRoadInfrastructureBuilder pTrI_builder;
    std::unique_ptr<RoadInfrastructure> tRinfrastructure= director.createRoadInfrastructure(tRi_builder);
    std::unique_ptr<RoadInfrastructure> pTrInfrastructure = director.createRoadInfrastructure(pTrI_builder);
    
    std::cout << "Hello road!" << std::endl;

    /*while(true) {
        if(mainTrafficLightTimingController)
            mainTrafficLightTimingController->update();
    }*/

    // Create double traffic light
    /*std::unique_ptr<ITrafficLight> doubleTrafficLight = createDoubleTrafficLight();
    doubleTrafficLight->allow();
    doubleTrafficLight->disallow();*/

    // Create triple traffic light
    std::unique_ptr<ITrafficLight> tripleTrafficLight = createTripleTafficLight();
    tripleTrafficLight->allow();

    return 0;
}
