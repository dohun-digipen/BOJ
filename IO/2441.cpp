#include <iostream>

int main(){
	int n;
	std::cin >> n;
	for(int i = n; i > 0; i--){
		for(int j = 0; j < n - i; j++){
			std::cout << " ";
		}
		for(int k = 0; k < i; k++){
			std::cout << "*";
		}
		std::cout << "\n";
	}
}