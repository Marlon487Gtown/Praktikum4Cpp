#include "Parallel.hpp"

Parallel::Parallel() {};
Parallel::~Parallel(){};


void Parallel::print()
{

	cout << "Gesamtwiderstand der Parallelschaltung ist " << this->calculateResistance() << " Ohm" << endl;
	cout << "Die Gesamtspannung der Parallelschaltung ist " << this->calculateVoltage() << "V" << endl;
	cout << "Strom der Parallelschaltung ist gleich " << this->calculateCurrent() * 1000 << "mA" << "\n" << endl;
};


double Parallel::calculateResistance()
{
	double temp = 0;
		
		for (const auto& component : this->components) {

			if (component->get_voltage() > 0) continue;

			if (component->get_resistance() == 0 )
			{
				cout << component->get_name() << endl;
				return 0;
			}

			temp += (1 / component->get_resistance());
		}

	return 1 / temp;
};


double Parallel::calculateVoltage()
{
	double Umax = 0;

	for (const auto& component : this->components) {

		if (component->get_voltage() > Umax) {

			Umax = component->get_voltage();
		}
	}

	return Umax;
};


double Parallel::calculateCurrent()
{
	return (calculateVoltage() / calculateResistance());
};