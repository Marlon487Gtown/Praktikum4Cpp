#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Component.hpp"

using namespace std;


class VoltageSource : public Component {

public:
	VoltageSource(string VoltageName, double voltage);
	void print();

private:

};