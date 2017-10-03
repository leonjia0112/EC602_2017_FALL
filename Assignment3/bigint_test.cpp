#include <iostream>
#include <vector>

using namespace std;

#include "bigint.cpp"

int main()
{ 

	BigInt A = "111111";
	BigInt B = "1111111";

	// Poly AA = int_to_poly(A);
	// Poly BB = int_to_poly(B);
	// // for(int i=0; i<n.size(); i++){
	// 	cout << n[i] << endl;
	// }

	// BigInt c = poly_to_int(n);
	// cout << c << endl;

	cout << multiply_int(A,B) << endl;

}