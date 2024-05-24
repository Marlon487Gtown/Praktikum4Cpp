#include "VoltageSource.hpp"

VoltageSource::VoltageSource(string voltagename, double voltage)
{
	this->ComponentName = voltagename;
	this->ComponentVoltage = voltage;
};

void VoltageSource:: print()
{
	if (this->ComponentVoltage != NULL)
	{
		cout << this->ComponentName << " = " << this->ComponentVoltage << " Ohm" << endl;
	}
	else
	{
		cout << "Keine Voltage initialiert" << endl;
	}
};


//double VoltageSource::get_voltage()
//{
//	return this->voltage;
//};
