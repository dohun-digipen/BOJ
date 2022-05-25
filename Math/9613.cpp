#include <iostream>

int gcd(int a, int b){
	if(a % b == 0){
		return b;
	}
	return gcd(b, a % b);
}

long GetGDCSum(long* arr, int n){
	long sum = 0;
	
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			sum += gcd(arr[i], arr[j]);
		}
	}
	return sum;
}

int main(){
	int t, n;
	long arr[100];
	
	std::cin >> t;
	
	for(int i = 0; i < t; i++){
		std::cin >> n;
		for(int j = 0; j < n; j++){
			std::cin >> arr[j];
		}
		std::cout << GetGDCSum(arr, n) << "\n";
	}
}