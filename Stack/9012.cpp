#include <iostream>
#include <string>
#include <stack>

int main(){
	std::string s, ans;
	int n;
	int fcnt = 0;
	int lcnt = 0;
	std::stack<char> stack;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		ans = "YES";
		for(int j = 0; j < s.length(); j++){
			if(s[j] == '('){
				stack.push(s[j]);
			}else if(s[j] == ')'){
				if(stack.empty()){
					ans = "NO";
					break;
				}else{
					stack.pop();
				}
			}
		}
		if(stack.empty() == false){
			ans = "NO";
			while(!stack.empty()){
				stack.pop();
			}
		}
		std::cout << ans << "\n";
	}
}