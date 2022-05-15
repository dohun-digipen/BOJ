#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int line = (2*n) - 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			std::cout << " ";
		}
		for(int k = 0; k < line - (2*i); k++){
			std::cout << "*";
		}
		std::cout << "\n";
	}
	
	for(int i = n - 2; i >= 0 ; i--){
		for(int j = 0; j < i; j++){
			std::cout << " ";
		}
		for(int k = 0; k < line - (2*i); k++){
			std::cout << "*";
		}
		std::cout << "\n";
	}
}