// Copyright 2017 Pei Jia leojia@bu.edu

#include <vector>
#include <string>

using namespace std;

int overflow_const = 10;

typedef string BigInt;
typedef vector<double> Poly;

BigInt multiply_int(const BigInt &a,const BigInt &b);
Poly int_to_poly(const BigInt& n);
BigInt poly_to_int(const Poly& n);
Poly multiply_poly(const Poly &a,const Poly &b);
Poly remove_zero_term(Poly result);
Poly overflow(Poly &a);


BigInt multiply_int(const BigInt &a,const BigInt &b){
	Poly result = multiply_poly(int_to_poly(a), int_to_poly(b));
	return poly_to_int(overflow(result));
}


// convert bigint to poly 
Poly int_to_poly(const BigInt& n){
	Poly result(n.size(), 0);
	for(int i=0; i<n.size(); i++){
		result[i] = n[n.size()-1-i]-'0';;
	}
	return result;
}


// convert poly to bigint
BigInt poly_to_int(const Poly& n){
	BigInt result;
	result.clear();
	result.resize(n.size());
	for(int i=0; i<n.size(); i++){
		result[i]=(int)n[n.size()-1-i]+'0';
	}
	return result;
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
	result = remove_zero_term(result);
	return result;
}


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


Poly overflow(Poly &a){
	Poly result = a;
	for(int i=0; i<result.size(); i++) {
		if(result[i]>(overflow_const-1)) {		
			if(i==result.size()-1) {				
				result.push_back((int)result[i]/overflow_const);			
			}else{						
				result[i+1] += (int)result[i]/overflow_const;
			}
			result[i] = ((int)result[i])%overflow_const;
		}
	}
	return result;
}


