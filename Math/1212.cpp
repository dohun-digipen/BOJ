#include <iostream>
#include <string>

std::string Reverse(std::string _s){
	int len = _s.length();
	std::string s;
	
	for(int i = len - 1; i >= 0; i--){
		s += _s[i];
	}
	
	return s;
}

std::string DecimalToBinary(int n){
	
	std::string s;
	while(true){
		int num = n % 2;
		if(n == 0){
			break;
		}
		
		s += std::to_string(num);
		n = n / 2;
	}
	
	while(s.length() != 3){
		s += '0';
	}
	s = Reverse(s);
	return s;
}

int main(){
	std::string s, bin;
	std::cin >> s;
	
	if(s[0] == '0'){
		std::cout << 0;
		return 0;
	}
	
	
	for(int i = 0; i < s.length(); i++){
		bin += DecimalToBinary(s[i] - '0');
	}
	
	for(int i = 0; i < bin.length(); i++){
		if(bin[i] == '1'){
			bin = bin.substr(i);
			break;
		}
	}
	
	std::cout << bin;
}