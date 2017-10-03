// Copyright 2017 Pei Jia leojia@bu.edu

//#include <iostream>
//#include <math.h>
#include <vector>

using namespace std;

typedef vector<double> Poly;

Poly add_poly(const Poly &a,const Poly &b);
Poly multiply_poly(const Poly &a,const Poly &b);
Poly remove_zero_term(Poly result);


// Add two polynomials, returning the result
Poly add_poly(const Poly &a,const Poly &b){
	Poly result;
	if(a.size() > b.size()){
		result = a;
		for(int i=0; i<b.size(); i++){
			result[i] += b[i];
		}
	}else{
		result = b;
		for(int j=0; j<a.size(); j++){
			result[j] += a[j];
		}
	}
	return remove_zero_term(result);
}


// Multiply two polynomials, returning the result.
Poly multiply_poly(const Poly &a,const Poly &b){
	Poly result;
	result.clear();
	result.resize(a.size()+b.size()-1,0);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			result[i+j] += (a[i]*b[j]);
		}
	}
	return remove_zero_term(result);
}


// Remove all the zero term from the end
Poly remove_zero_term(Poly result){
	for(int k=result.size()-1; k>0; k--){
		if(result[k] == 0 || result[k] == 0.0){
			result.erase(result.begin() + k);
		}else{
			break;
		}
	}
	return result;
}

