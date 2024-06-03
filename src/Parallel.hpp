#pragma once
#include <vector>
#include <iostream>
#include <string>
#include"Circuit.hpp"
using namespace std;


class Parallel : public Circuit {
public:

    Parallel();
    ~Parallel();
    double calculateResistance() override;
    double calculateVoltage() override;
    double calculateCurrent() override;
    void print();


private:

};