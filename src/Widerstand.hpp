#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "Component.hpp"

using namespace std;


class Widerstand : public Component {

public:
	Widerstand(string name, double wert);
	~Widerstand()=default;
	void print();

private:

};