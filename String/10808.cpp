#include <iostream>
#include <string>

int main(){
	std::string s;
	std::cin >> s;
	int arr[26] = {0};
	int n = 0;
	
	for(int i = 0; i < s.size(); i++){
		n = s[i] - 97;
		arr[n]++;
	}
	
	for(int i = 0; i < 26; i++){
		std::cout << arr[i] << " ";
	}
}