#include "Circuit.hpp"
#include <iostream>
#include <typeinfo>



Circuit::Circuit() {};

Circuit::~Circuit() {};


void Circuit::add_component(shared_ptr<Component> component)
{
	this->components.push_back(move(component));
};


void Circuit::print()
{
	for (const auto& component : this->components) {

		cout << component->get_name() << endl;

		if (component->get_resistance() != 0)
		{
			cout << component->get_resistance() << endl;
		}

		else if(component->get_voltage() != 0)
		{
			cout << component->get_voltage() << endl;
		}
	}

};
