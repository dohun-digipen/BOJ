#include <iostream>
#include <string>

int main(){
	int n;
	std::cin >> n;
	int ans = 0;
	
	for(int i = 5; i <= n; i*=5){
		ans += n / i;
	}
	
	std::cout << ans;
}