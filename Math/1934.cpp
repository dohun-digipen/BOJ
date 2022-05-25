#include <iostream>

int gcd(int a, int b){
	if(a % b == 0){
		return b;
	}
	return gcd(b, a % b);
}

int main(){
	int n, a, b, c;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> a >> b;
		std::cout << (a * b) / gcd(a, b) << "\n";
	}
}