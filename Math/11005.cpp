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

int main(){
	long long n;
	long long b;
	std::string s;
	std::cin >> n >> b;
	
	while(true){
		int num = n % b;
		if(n == 0){
			break;
		}
		
		if(num > 9){
			s += (char)(num + 55);
		}else{
			s += std::to_string(num);
		}
		
		n = n / b;
		
		
	}
	
	
	std::cout << Reverse(s);
}