#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Component {

public:
    Component();
    ~Component();
    string get_name();
    double get_resistance();
    double get_voltage();
    virtual void print()=0;

protected:
    string ComponentName="";
    double ComponentResistance {0.0};
    double ComponentVoltage{ 0.0 };
    double ComponentCurrent{ 0.0 };

};
