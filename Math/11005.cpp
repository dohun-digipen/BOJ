#include <iostream>
#include <string>

std::string ToString(int num){
	if(num < 10){
		return std::to_string(num);
	}
	std::string s = "7" + 55;
	return s;
}

int main(){
	long long n;
	long long b;
	std::string s;
	std::cin >> n >> b;
	
	while(true){
		if(b > n){
			s += ToString(n);
			break;
		}
		
		s += ToString(n / b);
		n = n / b;
		
		
	}
	std::cout << s;
}