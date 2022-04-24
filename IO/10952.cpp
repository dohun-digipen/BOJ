#include <iostream>
int main(){
	int a, b = 1;
	int n = 0;
	int arr[1000];
	while(!(a == 0 && b == 0)){
		
		std::cin >> a >> b;
		arr[n] = a + b;
		n++;
	}
	
	for(int i = 0; i < n - 1; i++){
		std::cout << arr[i] << std::endl;
	}
	
	return 0;
}