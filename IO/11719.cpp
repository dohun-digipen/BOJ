#include<iostream>
#include<string>
int main(){
	std::string arr[100];
	int n = 100;
	for(int i = 0; i < n; ++i){
		std::getline(std::cin, arr[i]);
	}
	for(int i = 0; i < n; ++i){
		std::cout << arr[i] << std::endl;
	}
}