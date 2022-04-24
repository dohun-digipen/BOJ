#include <iostream>

int main(){
	int m,n,total = 0;
	std::string s;
	std::cin >> n >> s;
	for(int i = 0; i < n; i++){
		m = int(s[i]) - 48;
		total += m;
	}
	std::cout << total;
}