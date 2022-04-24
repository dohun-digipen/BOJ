#include <iostream>

int main(){
	std::string s;
	int a,b,n,l;
	int arr[1000];
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		l = s.find(44);
		a = std::stoi(s.substr(0,l));
		b = std::stoi(s.substr(l+1));
		std::cout << a << " " << b << std::endl;
		arr[i] = a + b;
	}
	
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << std::endl;
	}
}