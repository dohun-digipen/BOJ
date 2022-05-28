#include <iostream>
#include <cmath>

//소수를 구하는 방법 -> 1부터 수까지 다 나누어 보고 만약 나누어지 떨어지는 수가 2개 뿐이라면 소수다.
int main(){
	int n, prime;
	
	std::cin >> n;
	
	int count = 0; 
	int total = 0;
	for(int i = 0; i < n; i++){
		std::cin >> prime;
		count = 0;
		for(int j = 1; j <= prime; j++){
			if(prime % j == 0){
				count++;
			}
		}
		if(count == 2){
			total++;
		}
	}
	std::cout << total;
}