#include<iostream>

int main(){
	std::string s;
	std::string arr[10000];
	int n = 0;
	
	std::cin >> s;
	
	while(true){
		if(s.length() < 10){
			arr[n] = s;
			n++;
			break;
		}
		
		arr[n] = s.substr(0,10);
		s = s.substr(10);
		n++;
	}
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << std::endl;
	}
}