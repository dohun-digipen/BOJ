#include<iostream>
#include<string>
int main(){
	std::string s;
	
	while(true){
		std::getline(std::cin, s);
		if(s == ""){
			break;
		}
		std::cout << s << std:: endl;
	}
}