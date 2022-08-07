#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

int main(){
	const int MAX = 1000001;
	std::string target, input, s;
	int n;
	std::cin >> target >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> s;
		input += s;
	}
	
	int len = input.length();
	bool isFound = false;
	int ans = std::abs(std::stoi(target) - 100);
	for(int i = 0; i < MAX; i++){
		isFound = true;
		for(int j = 0; j < len; j++){
			if(std::to_string(i).find(input[j]) != std::string::npos){
				isFound = false;
				break;
			}
		}
		if(isFound){
			if(ans > std::abs(i - std::stoi(target)) + std::to_string(i).length()){
				ans = std::abs(i - std::stoi(target)) + std::to_string(i).length();
			}
		}
	}
	
	std::cout << ans;
}