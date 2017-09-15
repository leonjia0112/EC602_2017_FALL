// Copyright 2017 Pei Jia leojia@bu.edu

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int hitPoint = 0;
	for(int i=1; i<argc; i++){
		if(hitPoint<4){
			cout << argv[i] << "\n";
			hitPoint++;
		}else{
			cerr << argv[i] << "\n";
		}
	}
	return 0;
}
