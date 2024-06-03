#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "Component.hpp"

using namespace std;


class Circuit :public Component {
    

protected:

    vector<shared_ptr<Component>> components;
    virtual double calculateResistance() = 0;
    virtual double calculateVoltage() = 0;
    virtual double calculateCurrent() = 0;

    
public:

    Circuit();
    ~Circuit();
    void add_component(shared_ptr<Component> component);
    virtual void print()=0;
    double getResistance();
    double getVoltage();
    double getCurrent();

};
