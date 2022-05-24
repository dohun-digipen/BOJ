#include <iostream>
#include <string>

int main(){
	std::string s;
	std::getline(std::cin, s);
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 97 && s[i] <= 122){
			if(s[i] + 13 > 122){
				s[i] = 96 + (s[i] + 13 - 122);
			}else{
				s[i] = s[i] + 13;
			}
		}else if(s[i] >= 65 && s[i] <= 90){
			if(s[i] + 13 > 90){
				s[i] = 64 + (s[i] + 13 - 90);
			}else{
				s[i] = s[i] + 13;
			}
		}
	}
	 std::cout << s << "\n";
}