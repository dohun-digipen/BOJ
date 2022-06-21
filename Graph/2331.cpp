#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::vector<int> arr;

int GetNum(std::string n, int p){
	int len = n.size();
	int total = 0;
	for(int i = 0; i < len; i++){
		total += std::pow(n[i] - '0', p);
	}
	return total;
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int  a, p;
	int ans = 0;
	std::cin >> a >> p;
	arr.push_back(a);
	while(true){
		a = GetNum(std::to_string(a), p);
		int len = arr.size();
		for(int i = 0; i < len; i++){
			if(arr[i] == a){
				ans = i;
				std::cout << ans;
				return 0;
			}
		}
		arr.push_back(a);
	}
}