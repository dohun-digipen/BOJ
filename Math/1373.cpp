#include <iostream>
#include <cmath>
#include <string>

std::string Reverse(std::string _s){
	int len = _s.length();
	std::string s;
	
	for(int i = len - 1; i >= 0; i--){
		s += _s[i];
	}
	
	return s;
}

std::string BinaryToDecimal(std::string s){
	int n = 0;
	int len = s.length();
	for(int i = 0; i < len; i++){
		int num;
		num = s[i] - '0';
		num = num * std::pow(2, len - 1 - i);
		n += num;
	}
	
	return std::to_string(n);
}

//2진수를 뒤에서 부터 3자리씩 끊어서 10진수로 변환 후 모두 나열하면 8진수가 된다.

int main(){
	
	std::string binary;
	std::string octal;
	
	std::cin >> binary;
	
	for(int i = binary.length() - 1; i >= 0; i -= 3){
		
		if(i < 3){
			std::string s2;
			s2 += binary.substr(0, i + 1);
			octal += BinaryToDecimal(s2);
			break;
		}
		
		std::string s;
		s = binary.substr(i - 2, 3);
		octal += BinaryToDecimal(s);
		
		
	}
	
	std::cout << Reverse(octal);
}