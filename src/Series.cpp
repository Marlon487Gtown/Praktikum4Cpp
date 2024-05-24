#include "Series.hpp"


Series::Series() {};
Series::~Series(){};

void Series::print()
{
	cout <<"Gesamtwiderstand der Reihenschaltung ist "<< this->calculateResistance() <<" Ohm"<< endl;
	cout << "Die Gesamtspannung der Reihenschaltung ist " << this->calculateVoltage() << "V" << endl;
	cout << "Der Gesamtstrom der Reihenschaltung ist " << this->calculateCurrent() * 1000 << "mA\n" << endl;
};


double Series::calculateResistance()
{
	double result = 0.0;

	for (const auto& component : this->components) {

		result += component->get_resistance();
	}
	return result;
};

double Series::calculateVoltage()
{
	double result = 0.0;

	for (const auto& component : this->components) {

		result += component->get_voltage();
	}
	
	return result;
};

double Series::calculateCurrent()
{
	double result = 0.0;

	result = (this->calculateVoltage() / this->calculateResistance());


	return result;
};

