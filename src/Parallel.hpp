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
    /*double ParallelResult=0.0;
    double Uparallel = 0.0;
    double Iparallel = 0.0;*/
    
};