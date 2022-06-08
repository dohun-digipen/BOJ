#include <iostream>
#include <cstdlib>
#include <vector>

int max = 0;

int Sum(int* arr, int len){
	int sum = 0;
	for(int i = 0; i < len - 1; i++){
		sum += std::abs(arr[i] - arr[i + 1]);
	}
	return sum;
}

void GetMax(int* arr,int* ordered, int curIdx, int len){
	int sum = 0;
	std::vector<int> idx;
	if(curIdx == len){
		sum = Sum(ordered, len);
		if(sum > max){
			max = sum;
		}
		
		//todo : arr clear
		for(int i = 0; i < len; i++){
			std::cout << ordered[i] << " ";
			ordered[i] = -101;
		}
		std::cout << "\n";
		return;
	}
	
	int n;
	bool flag = false;
	for(int i = 0; i < len - curIdx; i++){
		std::cout << ordered[i] << " ";
		for(int j = 0; j < len; j++){
			if(ordered[i] == arr[j]){
				flag = true;
			}
			n = j;
		}
		if(flag == false){
			idx.push_back(n);
		}else{
			flag = false;
		}
		std::cout << "\n";
	}
	
	for(auto i : idx){
		
		ordered[curIdx] = arr[i];
		GetMax(arr, ordered, curIdx + 1, len);
	}
}

int main(){
	int* arr;
	int* ordered;
	int n, num;
	std::cin >> n;
	arr = new int(n);
	ordered = new int(n);
	for(int i = 0; i < n; i++){
		std::cin >> num;
		arr[i] = num;
	}
	
	GetMax(arr, ordered, 0, n);
	std::cout << max;
}