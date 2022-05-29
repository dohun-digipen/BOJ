#include <iostream>

int Factorial(int n){
	if(n == 1 || n == 0){
		return 1;
	}
	return Factorial(n - 1) * n;
}

int main(){
	int n;
	std::cin >> n;
	std::cout << Factorial(n);
}