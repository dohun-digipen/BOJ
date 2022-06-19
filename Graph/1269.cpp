#include <iostream>

const int MAX = 200001;

int arr[2][MAX];
bool hash[2][100000000] = {false};

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, k, a, b;
	std::cin >> n >> k;
	a = n;
	b = k;
	for(int i = 0; i < n; i++){
		std::cin >> arr[0][i];
		hash[0][arr[0][i]] = true;
	}
	for(int i = 0; i < k; i++){
		std::cin >> arr[1][i];
		hash[1][arr[1][i]] = true;
	}
	
	for(int i = 0; i < n; i++){
		if(hash[1][arr[0][i]] == true){
			a--;
		}
	}
	for(int i = 0; i < k; i++){
		if(hash[0][arr[1][i]] == true){
			b--;
		}
	}
	
	std::cout << a + b;
}