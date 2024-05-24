#include<iostream>
#include<vector>
#include <string>
using namespace std;

#include "Circuit.hpp"
#include "Parallel.hpp"
#include "Series.hpp"
#include "Widerstand.hpp"
#include "VoltageSource.hpp"

//penis

int main() 
{    

    //Teilschaltung 1
    cout << "Teilschaltung 1" << endl;
    auto V1 = make_unique<VoltageSource>("V1", 10);
    auto R1 = make_unique<Widerstand>("R1", 11);
    auto R2 = make_unique<Widerstand>("R2", 22);
    Series series1;
    series1.add_component(move(R1));
    series1.add_component(move(R2));
    series1.add_component(move(V1));
    auto s1GesamtWiderstand = make_unique<Widerstand>("", series1.calculateResistance());

    series1.calculateResistance();
    series1.calculateVoltage();
    series1.calculateCurrent();
    series1.print();

    //Teilschaltung 2
    cout << "Teilschaltung 2" << endl;
    auto V2 = make_unique<VoltageSource>("V2", 20);
    auto R3 = make_unique<Widerstand>("R3", 33.0);
    auto R4 = make_unique<Widerstand>("R4", 44.0);
    Parallel parallel1;
    parallel1.add_component(move(R3));
    parallel1.add_component(move(R4));
    auto p1GesamtWiderstand = make_unique<Widerstand>("", parallel1.calculateResistance());
    parallel1.add_component(move(V2));

    parallel1.calculateResistance();
    parallel1.calculateVoltage();
    parallel1.calculateCurrent();
    parallel1.print();

    //Teilschaltung 3
    cout << "Teilschaltung 3" << endl;
    auto V3 = make_unique<VoltageSource>("V3", 30);
    auto R5 = make_unique<Widerstand>("R5",55 );
    auto R6 = make_unique<Widerstand>("R6",66);
    Parallel parallel2;
    parallel2.add_component(move(R5));
    parallel2.add_component(move(R6));
    auto p2GesamtWiderstand = make_unique<Widerstand>("", parallel2.calculateResistance());
    parallel2.add_component(move(V3));

    parallel2.calculateResistance();
    parallel2.calculateVoltage();
    parallel2.calculateCurrent();
    parallel2.print();


    //Alle Teilschaltungen jeweils in Reihe
    cout << "Alle Teilschaltungen jeweils in Reihe" << endl;
    Series seriesN;
    seriesN.add_component(move(s1GesamtWiderstand));
    seriesN.add_component(move(p1GesamtWiderstand));
    seriesN.add_component(move(p2GesamtWiderstand));
    seriesN.add_component(move(V1));
    seriesN.add_component(move(V2));
    seriesN.add_component(move(V3));

    seriesN.calculateResistance();
    seriesN.calculateVoltage();
    seriesN.calculateCurrent();
    seriesN.print();

    //Alle Teilschaltungen jeweils Parallel
    cout << "Alle Teilschaltungen jeweils Parallel" << endl;
    Parallel paralellN;
    paralellN.add_component(move(s1GesamtWiderstand));
    paralellN.add_component(move(p1GesamtWiderstand));
    paralellN.add_component(move(p2GesamtWiderstand));
    paralellN.add_component(move(V1));
    paralellN.add_component(move(V2));
    paralellN.add_component(move(V3));

    paralellN.calculateResistance();
    paralellN.calculateVoltage();
    paralellN.calculateCurrent();
    paralellN.print();



    return 0;
}
