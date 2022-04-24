#include <iostream>

int main(){
	int a,b,n;
	int arr[1000][3];
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = a+b;
	}
	
	for(int i = 0; i < n; i++){
		std::cout << "Case #" << i + 1 << ": " 
			<< arr[i][0] << " + " << arr[i][1] 
			<< " = " << arr[i][2] << std::endl;
	}
}