#include <iostream>
#include <string>

int main(){
	std::string s, temp, max;
	std::string arr[1000];
	int n;
	
	std::cin >> s;
	n = s.length();
	
	for(int i = 0; i < n; i++){
		arr[i] = s.substr(i);
	}
	
	
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << std::endl;
	}
}