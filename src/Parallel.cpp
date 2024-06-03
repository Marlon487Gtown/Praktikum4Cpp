#include "Parallel.hpp"
#include "VoltageSource.hpp"
#include "Component.hpp"
#include "Circuit.hpp"
#include <typeinfo>

using namespace std;

Parallel::Parallel() {};
Parallel::~Parallel(){};


void Parallel::print()
{

	cout << "Gesamtwiderstand der Parallelschaltung ist " << this->calculateResistance() << " Ohm" << endl;
	cout << "Die Gesamtspannung der Parallelschaltung ist " << this->calculateVoltage() << "V" << endl;
	cout << "Strom der Parallelschaltung ist gleich " << this->calculateCurrent() * 1000 << "mA" << "\n" << endl;
};



//if (dynamic_cast<VoltageSource*>(component) != nullptr)  continue ;
//if (component->get_voltage() > 0) continue;


double Parallel::calculateResistance()
{
	double temp{ 0.0 };

	for (const auto& component : this->components) {

		if (component->get_voltage() > 0) continue; //jetztige Lösung (funktioniert)

		if (typeid(component) == typeid(VoltageSource))  //saubere typeid Lösung muss noch gefixt werden.
		{ 
			cout << "typeid" << endl;
			continue; 
		}

		if (component->get_resistance() == 0)
		{
			cout << component->get_name() <<" hat einen Widerstand von 0 Ohm" << endl;
			return 0;
		}

		temp += (1 / component->get_resistance());
	}


	if (temp == 0) {
		cout << "Geteilt durch 0" << endl;
		return 0;
	}

	return 1 / temp;
};


double Parallel::calculateVoltage()
{
	double Umax{ 0.0 };

	for (const auto& component : this->components) {

		if (component->get_voltage() > Umax) {

			Umax = component->get_voltage();
		}
	}

	return Umax;
};


double Parallel::calculateCurrent()
{
	double result{ 0.0 };

	if (this->calculateResistance() != 0) {
		result = (this->calculateVoltage() / this->calculateResistance());
	}
	else cout << "Geteilt durch 0" << endl;


	return result;
};