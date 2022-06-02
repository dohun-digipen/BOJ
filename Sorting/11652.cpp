#include <iostream>
#include <algorithm>

int main(){
	long long arr[100000];
	int n;
	long long a;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> a;
		arr[i] = a;
	}
	std::sort(arr, arr + n);
	
	long long maxNum = arr[0];
	int maxCount = 1;
	int count = 1;
	for(int i = 0; i < n - 1; i++){
		if(arr[i] == arr[i + 1]){
			count++;
		}else{
			count = 1;
		}
		if(maxCount < count){
			maxCount = count;
			maxNum = arr[i];
		}
	}
	std::cout << maxNum;
}