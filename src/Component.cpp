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
