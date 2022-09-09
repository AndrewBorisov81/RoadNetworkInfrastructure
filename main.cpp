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
#include "src/TrafficLight.h"
#include "src/DoubleTrafficLight.h"
#include "src/ITrafficLightsController.h"
#include "src/TrafficLightsController.h"
#include "src/ControllerStateMachine.h"
#include "src/ControllerLogicModule.h"
#include "src/TrafficLightsTimingController.h"
#include "src/ITrafficLightsTimingController.h"

std::unique_ptr<CrossRoads> createCrossroad() {
    return std::make_unique<CrossRoads>();
}

std::vector<TypeTrafficLight> vTrafficLights{TypeTrafficLight::DOUBLE_TRANS, TypeTrafficLight::DOUBLE_PEOPLE};

/*std::unique_ptr<ITrafficLight> createTrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {

    return std::make_unique<TrafficLight>(typeTrafficLight, lightBulbs);
}*/

std::unique_ptr<ITrafficLight> createTrafficLight(TrafficLightImpl * pimpl, TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {

    return std::make_unique<TrafficLight>(pimpl);
}

/*std::unique_ptr<ITrafficLight> createDoubleTrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {
     
}*/

std::unique_ptr<ILightBulb> createLightBulb(ColorLightBulb colorBulb) {
    return std::make_unique<LightBulb>(colorBulb);
}

std::unique_ptr<ILightBulb> createLightBulb() {
    return std::make_unique<LightBulb>();
}

std::vector<ColorLightBulb> vLightBulbs{ColorLightBulb::RED, ColorLightBulb::GREEN};

std::vector<std::unique_ptr<ILightBulb>> createLightBulbs(const std::vector<ColorLightBulb>& vfLightBulbs) {
    
    std::vector<std::unique_ptr<ILightBulb>> vLightBulbs;
    
    for(const ColorLightBulb& color : vfLightBulbs) {
        switch(color) {
            case ColorLightBulb::RED:
                vLightBulbs.emplace_back(std::make_unique<LightBulb>());
                break;
                
            case ColorLightBulb::GREEN:
                vLightBulbs.emplace_back(std::make_unique<LightBulb>());
                break;
                
            default:
                break;
        };
    }
    return vLightBulbs;
}

std::unique_ptr<ControllerStateMachine> createControllerStateMachine() {
    return std::make_unique<ControllerStateMachine>();
}

std::unique_ptr<ITrafficLightsTimingController> createTrafficLightsTimingController() {
    return std::make_unique<TrafficLightsTimingController>();
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
    
    return 0;
}

