#include <iostream>
#include <cmath>
#include <vector>

//에라토스테네스의 체 알고리즘

int main(){
	int n;
	bool arr[10000000];
	std::vector<int> prime;
	std::cin >> n;
	
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
	
	for(int i = 2; i <= n; i++){
		if(arr[i] == true){
			prime.push_back(i);
		}
	}
	
	int i = 0;
	while(n != 1){
		if(n % prime[i] == 0){
			std::cout << prime[i] << "\n";
			n = n / prime[i];
		}else{
			i++;
		}
	}
}