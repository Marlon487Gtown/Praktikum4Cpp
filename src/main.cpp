#include<iostream>
#include<vector>
#include <string>
using namespace std;

#include "Circuit.hpp"
#include "Parallel.hpp"
#include "Series.hpp"
#include "Widerstand.hpp"
#include "VoltageSource.hpp"


int main() 
{    
    
    //Teilschaltung 1
    cout << "Teilschaltung 1" << endl;
    auto V1 = make_shared<VoltageSource>("V1", 10);
    auto R1 = make_shared<Widerstand>("R1", 11);
    auto R2 = make_shared<Widerstand>("R2", 22);
    Series series1;
    series1.add_component(R1);
    series1.add_component(R2);
    series1.add_component(V1);
    auto s1GesamtWiderstand = make_shared<Widerstand>("", series1.getResistance());

    series1.getResistance();
    series1.getVoltage();
    series1.getCurrent();
    //series1.calculateResistance();
    //series1.calculateVoltage();
    //series1.calculateCurrent();
    series1.print();

    //Teilschaltung 2
    cout << "Teilschaltung 2" << endl;
    auto V2 = make_shared<VoltageSource>("V2", 20);
    auto R3 = make_shared<Widerstand>("R3", 33.0);
    auto R4 = make_shared<Widerstand>("R4", 44.0);
    Parallel parallel1;
    parallel1.add_component(R3);
    parallel1.add_component(R4);
    auto p1GesamtWiderstand = make_shared<Widerstand>("", parallel1.getResistance());
    parallel1.add_component(V2);

    parallel1.getResistance();    
    parallel1.getVoltage();
    parallel1.getCurrent();
    //parallel1.calculateResistance();
    //parallel1.calculateVoltage();
    //parallel1.calculateCurrent();
    parallel1.print();

    //Teilschaltung 3
    cout << "Teilschaltung 3" << endl;
    auto V3 = make_shared<VoltageSource>("V3", 30);
    auto R5 = make_shared<Widerstand>("R5",55 );
    auto R6 = make_shared<Widerstand>("R6",66);
    Parallel parallel2;
    parallel2.add_component(R5);
    parallel2.add_component(R6);
    auto p2GesamtWiderstand = make_shared<Widerstand>("", parallel2.getResistance());
    parallel2.add_component(V3);

    parallel2.getResistance();
    parallel2.getVoltage();
    parallel2.getCurrent();
    //parallel2.calculateResistance();
    //parallel2.calculateVoltage();
    //parallel2.calculateCurrent();
    parallel2.print();


    //Alle Teilschaltungen jeweils in Reihe
    cout << "Alle Teilschaltungen jeweils in Reihe" << endl;
    Series seriesN;
    seriesN.add_component(s1GesamtWiderstand);
    seriesN.add_component(p1GesamtWiderstand);
    seriesN.add_component(p2GesamtWiderstand);
    seriesN.add_component(V1);
    seriesN.add_component(V2);
    seriesN.add_component(V3);

    seriesN.getResistance();
    seriesN.getVoltage();
    seriesN.getCurrent();
    //seriesN.calculateResistance();
    //seriesN.calculateVoltage();
    //seriesN.calculateCurrent();
    seriesN.print();

    //Alle Teilschaltungen jeweils Parallel
    cout << "Alle Teilschaltungen jeweils Parallel" << endl;
    Parallel paralellN;
    paralellN.add_component(s1GesamtWiderstand);
    paralellN.add_component(p1GesamtWiderstand);
    paralellN.add_component(p2GesamtWiderstand);
    paralellN.add_component(V1);
    paralellN.add_component(V2);
    paralellN.add_component(V3);

    paralellN.getResistance();
    paralellN.getVoltage();
    paralellN.getCurrent();
    //paralellN.calculateResistance();
    //paralellN.calculateVoltage();
    //paralellN.calculateCurrent();
    paralellN.print();
    


    return 0;
}
