#include <iostream>
#include <algorithm>

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, a, min, idx;
	int arr[1000000];
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> a;
		arr[i] = a;
	}
	std::sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << "\n";
	}

}