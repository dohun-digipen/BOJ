#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int line = 2*n;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			std::cout << "*";
		}
		for(int k = 0; k < line - (2*i); k++){
			std::cout << " ";
		}
		for(int j = 0; j < i; j++){
			std::cout << "*";
		}
		std::cout << "\n";
	}
	
	for(int i = n; i > 0 ; i--){
		for(int j = 0; j < i; j++){
			std::cout << "*";
		}
		for(int k = 0; k < line - (2*i); k++){
			std::cout << " ";
		}
		for(int j = 0; j < i; j++){
			std::cout << "*";
		}
		std::cout << "\n";
	}
}