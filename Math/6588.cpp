#include <iostream>
#include <cmath>

int main(){
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	int n;
	bool arr[1000002];
	
	for(int i = 2; i <= 1000001; i++){
		arr[i] = true;
	}
	
	for(int i = 2; i * i <= 1000001; i++){
		if(arr[i] == true){
			for(int j = 2 * i; j <= 1000001; j += i){
				arr[j] = false;
			}
		}
	}
	
	while(1){
		bool flag = false;
		std::cin >> n;
		if(n == 0){
			break;
		}
		for(int i = 3; i <= n / 2; i+=2){
			if(arr[i] == true && arr[n - i] == true){
				std::cout << n << " = " << i << " + " << n - i << "\n";
				flag = true;
				break;
			}
		}
		if(flag == false){
			std::cout << "Goldbach's conjecture is wrong." << "/n";
		}
	}
}