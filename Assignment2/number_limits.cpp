// Copyright 2017 Pei Jia leojia@bu.edu

#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <math.h>

using namespace std;

int main(){
	double Rs,Ri,Rm;
	double largest_float_int_16, largest_float_value_16, smallest_greater_than_zero_16;
	double largest_float_int_32, largest_float_value_32, smallest_greater_than_zero_32;
	double largest_float_int_64, largest_float_value_64, smallest_greater_than_zero_64;

	int16_t largest_int_16;
	int32_t largest_int_32;
	int64_t largest_int_64;

	// max integer of signed integer for 16, 32, 64
	largest_int_16 = 32767;
	largest_int_32 = 2147483647;
	largest_int_64 = 9223372036854775807;

	// max integer that can be represent by half/float/double without losing precision
	// 16 bit half precision has 10 fraction bit then the max for half precision is 2^11
	// 32 bit single precision has 23 fraction bit(matissa) then the max for float is 2^24
	// the same for 64 double precision 
	largest_float_int_16 = 2048;
	largest_float_int_32 = 16777216;
	largest_float_int_64 = 9007199254740992;

	// max value for a half/float/double
	// front wiki page
	largest_float_value_16 = 65504;
	largest_float_value_32 = 3.402823466e38;
	largest_float_value_64 = 1.7976931348623157e308;

	// smallest value larger than 0
	// for half the smallest positive value, not the subnormal value
	// 0 00001 0000000000
	smallest_greater_than_zero_16 = 6.10352e-5;
	smallest_greater_than_zero_32 = 1.175494351e-38;
	smallest_greater_than_zero_64 = 2.2250738585072014e-308;

	// calculate Rs, Ri, and Rm for half/binary16 vs int16_t
	Rs = 1 / smallest_greater_than_zero_16;
	Rm = largest_float_value_16 / largest_int_16;
	Ri = largest_int_16 / largest_float_int_16;
	std::cout<< "16 : Ri= " << Ri << " Rm= " << Rm << " Rs= " << Rs << std::endl;

	// calculate Rs, Ri, and Rm for float/single/binary32 vs int32_t
	Rs = 1/smallest_greater_than_zero_32;
	Rm = largest_float_value_32 / largest_int_32;
	Ri = largest_int_32 / largest_float_int_32;
	std::cout<< "32 : Ri= " << Ri << " Rm= " << Rm << " Rs= " << Rs << std::endl;

	// calculate Rs, Ri, and Rm for double/binary64 vs int64_t
	Rs = 1/smallest_greater_than_zero_64;
	Rm = largest_float_value_64 / largest_int_64;
	Ri = largest_int_64 / largest_float_int_64;
	std::cout<< "64 : Ri= " << Ri << " Rm= " << Rm << " Rs= " << Rs << std::endl;

	return 0;
}