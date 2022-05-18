#include <iostream>
#include <string>

int main(){
	int arr[4] = {0,};
	int n = 0;
	
	while(1){
		std::string s;
		
		std::getline(std::cin, s);
		if(s.length()==0){
			break;
		}
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
		arr[3] = 0;
		for(int j = 0; j < s.size(); j++){
			 if(s[j] >= 97 && s[j] <= 122){
				 arr[0]++;
			 }else if(s[j] >= 65 && s[j] <= 90){
				 arr[1]++;
			 }else if(s[j] >= 48 && s[j] <= 57){
				 arr[2]++;
			 }else if(s[j] == 32){
				 arr[3]++;
			 }
		 }
		std::cout << arr[0] << " " << arr[1] << " "
				 << arr[2] << " " <<arr[3] << "\n";
	}
}