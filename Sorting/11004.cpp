#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, k;
	long* arr;
	long a;
	std::cin >> n >> k;
	arr = new long[n];
	for(int i = 0; i < n; i++){
		std::cin >> a;
		arr[i] = a;
	}
	std::sort(arr, arr + n);
	std::cout << arr[k - 1];
}