//
//  main.cpp
//  RoadNetworkInfrastructure
// Paterns:
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
#include "src/TrafficLight.h"
#include "src/TransTrafficLight.h"
#include "src/PeopleTrafficLight.h"
#include "src/ControllerStateMachine.h"
#include "src/TrafficLightsTimingController.h"
#include "src/ITrafficLightsTimingController.h"

std::unique_ptr<CrossRoads> createCrossroad() {
    return std::make_unique<CrossRoads>();
}

std::vector<TypeTrafficLight> vTrafficLights{TypeTrafficLight::DOUBLE_TRANS, TypeTrafficLight::DOUBLE_PEOPLE};

std::unique_ptr<ITrafficLight> createTrafficLight(TypeTrafficLight typeTrafficLight, std::vector<std::unique_ptr<ILightBulb>>& lightBulbs) {

    return std::make_unique<TrafficLight>(typeTrafficLight, lightBulbs);
}

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

// Builder

int main(int argc, const char * argv[]) {
    std::vector<std::unique_ptr<ILightBulb>> vBulbs(createLightBulbs(vLightBulbs));
    std::unique_ptr<ITrafficLight> mainTrafficLight = createTrafficLight(TypeTrafficLight::DOUBLE_TRANS, vBulbs);
    std::unique_ptr<ControllerStateMachine> mainControllerStateMachine(std::move(createControllerStateMachine()));
    std::unique_ptr<ITrafficLightsTimingController> mainTrafficLightTimingController(std::move(createTrafficLightsTimingController()));
    
    std::cout << "Hello road!" << std::endl;

    /*while(true) {
        if(mainTrafficLightTimingController)
            mainTrafficLightTimingController->update();
    }*/
    
    return 0;
}

