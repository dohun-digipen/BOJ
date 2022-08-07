#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<int> vec;
bool visited[8];
int arr[8];
int n;
int max = 0;

int Sum(const std::vector<int>& arr){
	int sum = 0;
	int len = arr.size();
	for(int i = 0; i < len - 1; i++){
		sum += std::abs(arr[i] - arr[i + 1]);
	}
	return sum;
}

void GetMax(int cnt){
	if(cnt == n){
		int sum = Sum(vec);
		if(sum > max){
			max = sum;
		} 
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(visited[i] == false){
			visited[i] = true;
			vec.push_back(arr[i]);
			GetMax(cnt + 1);
			vec.pop_back();
			visited[i] = false;
		}
	}
}

int main(){
	int a;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> a;
		arr[i] = a;
	}
	GetMax(0);
	std::cout << max;
}