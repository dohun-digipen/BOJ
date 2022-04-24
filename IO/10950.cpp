#include <iostream>

int main(){
	int n, a, b;
	int arr[1000] = {0,};
	std::cin >> n;
	for(int i = 0; i < n; i++){
		a = 0;
		b = 0;
		std::cin >> a >> b;
		arr[i] = a + b;
	}
	
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << std::endl;
	}
	
	return 0;
}