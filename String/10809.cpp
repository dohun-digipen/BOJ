#include <iostream>
#include <string>

int main(){
	std::string s;
	std::cin >> s;
	int arr[26];
	int n = 0;
	
	for(int i = 0; i < 26; i++){
		arr[i] = -1;
	}
	
	for(int i = 0; i < s.size(); i++){
		n = s[i] - 97;
		if(arr[n] == -1){
			arr[n] = i;
		}
	}
	
	for(int i = 0; i < 26; i++){
		std::cout << arr[i] << " ";
	}
}