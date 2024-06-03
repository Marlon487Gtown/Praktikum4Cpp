#include "Widerstand.hpp"

Widerstand::Widerstand(string name, double wert)
{
	this->ComponentName = name;
	this->ComponentResistance = wert;
};



void Widerstand::print() {

	if (this->ComponentResistance != NULL)
	{
		cout << this->ComponentName << " = " << this->ComponentResistance << " Ohm" << endl;
	}
	else
	{
		cout << "Kein Widerstandswert initialiert" << endl;
	}
};
