#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "Component.hpp"

using namespace std;


class Circuit :public Component {
    

protected:
    //vector<Component*> components; //erzeugen eines Vektor worin alles gespeichert ist
    vector<shared_ptr<Component>> components;


    
public:

    Circuit();
    ~Circuit();
    void add_component(shared_ptr<Component> component);
    void print();
    virtual double calculateResistance() = 0;
    virtual double calculateVoltage() = 0;
    virtual double calculateCurrent() = 0;
};
