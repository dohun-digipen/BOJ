#include <iostream>
#include <string>

int main(){
	std::string s;
	std::cin >> s;
	int len = s.length();
	int stick = 0;
	int ans = 0;
	for(int i = 0; i < len; i++){
		if(i < len - 1){
			if(s[i] == '(' && s[i + 1] == ')'){
				ans += stick;
				i++;
			}else{
				if(s[i] == '('){
					stick++;
				}else{
					stick--;
					ans++;
				}
			}
		}else{
			ans++;
		}
	}
	std::cout << ans;
}