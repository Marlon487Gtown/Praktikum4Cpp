#pragma once
#include <vector>
#include <iostream>
#include <string>
#include"Circuit.hpp"

using namespace std;

class Series : public Circuit {
public:

    Series();
    ~Series();
    double calculateResistance() override;
    double calculateCurrent() override;
    double calculateVoltage() override;
    void print();


private:

};