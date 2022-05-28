#include <iostream>
#include <cmath>
#include <string>

int main(){
	std::string s;
	long long n = 0;
	int b;
	std::cin >> s >> b;
	int len = s.length();
	for(int i = 0; i < len; i++){
		long long num;
		if(s[i] >= 'A'){
			num = s[i] - 55;
		}else{
			num = s[i] - '0';
		}
		num = num * std::pow(b, len - 1 - i);
		n += num;
	}
	
	std::cout << n;
}