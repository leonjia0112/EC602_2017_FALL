// Copyright 2017 Pei Jia leojia@bu.edu
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double mass_earth, mole, terabyte;
	double carbon_mole_mass, carbon_electron;
	double uranium_mole_mass, uranium_electron;
	double average_electron_number, lower_electron_number, upper_electron_number;

	mass_earth = 5.972*pow(10, 24)*pow(10, 3);
	mole = 6.022e23;
	uranium_mole_mass = 238;
	uranium_electron = 92;
	carbon_mole_mass = 12;
	carbon_electron = 6;
	terabyte = 8796093022208;

	// Assume the all atom are carbon
	average_electron_number = mass_earth * mole * carbon_electron / (carbon_mole_mass * terabyte);

	// Assume the all atom are Uranium
	lower_electron_number = average_electron_number * carbon_mole_mass*uranium_electron /
		(uranium_mole_mass * carbon_electron);

	// Assume the all atom are hydrogen
	upper_electron_number = average_electron_number * carbon_mole_mass;

	cout << average_electron_number << "\n" << lower_electron_number << "\n"
		<< upper_electron_number << endl;
}