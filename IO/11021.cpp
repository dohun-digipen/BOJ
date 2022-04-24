#include <iostream>

int main(){
	int a,b,n;
	int arr[1000];
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> a >> b;
		arr[i] = a+b;
	}
	
	for(int i = 0; i < n; i++){
		std::cout << "Case #" << i + 1 << ": " 
			<< arr[i] << std::endl;
	}
}