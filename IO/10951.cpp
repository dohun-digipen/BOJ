#include <iostream>
int main(){
	int a,b,n;
	int arr[1000];
	while(!(std::cin >> a >> b).eof()){
		arr[n] = a + b;
		n++;
	}
	
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << std::endl;
	}
	return 0;
}