#include <iostream>
#include <string>
#include <algorithm>

int a[100000];
std::string s;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> s;
	int len = s.size();
	int sum = 0;
	for(int i = 0; i < len; i++){
		a[i] = s[i] - '0';
		sum += a[i];
	}
	std::sort(a, a + len);
	if(a[0] == 0 && sum % 3 == 0){
		for(int i = len - 1; i >= 0; i--){
			std::cout << a[i];
		}
	}else{
		std::cout << -1;
	}
}