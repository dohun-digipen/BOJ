#include <iostream>

int main(){
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n - i; j++){
			std::cout << " ";
		}
		for(int k = 0; k < (2 * i) - 1; k++){
			std::cout << "*";
		}
		std::cout << "\n";
	}
}