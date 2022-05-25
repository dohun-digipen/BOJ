#include <iostream>
#include <cmath>

long long gcd(long long a, long long b){
	if(a % b == 0){
		return b;
	}
	return gcd(b, a % b);
}

int main(){
	long long a, b, n;
	std::cin >> a >> b;
	n = gcd(a, b);
	for(long long i = 0; i < n; i++){
		std::cout << "1";
	}
}