#include <iostream>
#include <string>

int main(){
	std::string s[4];
	unsigned long long int n = 0;
	for(int i = 0; i < 4; ++i){
		std::cin >> s[i];
	}
	s[0] = s[0] + s[1];
	s[1] = s[2] + s[3];
	
	n = stoull(s[0]) + stoull(s[1]);
	std::cout << n;
}