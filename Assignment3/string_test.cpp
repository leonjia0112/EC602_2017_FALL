#include <iostream>
#include <vector>
#include <string>

int main(){

	int i = 3;
	std::string str = std::to_string(i);

	str.append(std::to_string(10));
	std::cout << str << std::endl;
}