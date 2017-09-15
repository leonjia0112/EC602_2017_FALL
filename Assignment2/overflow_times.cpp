// Copyright 2017 Pei Jia leojia@bu.edu
#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <math.h>

// using std name space for function
using namespace std;

// function protoype
void printTime(double unsigned_8, double unsigned_16, double unsinged_32, double unsigned_64);

int main(int argc, char* argv[])
{
	// calculate how long uint16_t takes to wrap around
	uint16_t m = 1;
	clock_t start_clock, end_clock;
	start_clock = clock();
	while (m>0){ m++; }
	end_clock = clock();
	double seconds = static_cast<double>(end_clock - start_clock) / CLOCKS_PER_SEC;

	// calculate the overflow time for other int type base on the int 16 measured time
	double int16_time = seconds*(pow(10, 6));
	double int8_time = seconds*pow(10, 9)/pow(2, 8);
	double int32_time = seconds*(pow(2, 16));
	double int64_time = seconds*(pow(2, 48)/(3600*24*365));

	printTime(int8_time, int16_time, int32_time, int64_time);

	return 0;
}

// function output the time value to standard output
void printTime(double unsigned_8, double unsigned_16, double unsinged_32, double unsigned_64)
{
	std::cout << "estimated int8 time (nanoseconds): " << unsigned_8 << std::endl;
	std::cout << "measured int16 time (microseconds): " << unsigned_16 << std::endl;
	std::cout << "estimated int32 time (seconds): " << unsinged_32 << std::endl;
	std::cout << "estimated int64 time (years): " << unsigned_64 << std::endl;
}


