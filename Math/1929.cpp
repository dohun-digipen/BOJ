#include <iostream>
#include <cmath>

//에라토스테네스의 체 알고리즘

int main(){
	int m ,n;
	bool arr[1000000];
	std::cin >> m >> n;
	
	for(int i = 2; i <= n; i++){
		arr[i] = true;
	}
	
	for(int i = 2; i * i <= n; i++){
		if(arr[i] == true){
			for(int j = i * i; j <= n; j += i){
				arr[j] = false;
			}
		}
	}
	
	for(int i = m; i <= n; i++){
		if(arr[i] == true){
			std::cout << i << "\n";
		}
	}
}