#include"Component.hpp"


Component::Component() {};
Component::~Component() 
{
};

string Component::get_name() 
{
	return this->ComponentName;
};

double Component::get_resistance()
{
	return this->ComponentResistance;
};

double Component::get_voltage()
{
	return this->ComponentVoltage;
};

double Component::get_current()
{
	//this->ComponentCurrent = (this->ComponentVoltage / this->ComponentResistance);

	return this->ComponentCurrent;
};