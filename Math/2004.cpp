#include <iostream>

int CountTwo(long m){
	int ans = 0;

	for(long i = 2; i <= m; i *= 2){
		ans += m / i;
	}
	
	return ans;
}

int CountFive(long m){
	int ans = 0;
	for(long i = 5; i <= m; i *= 5){
		ans += m / i;
	}
	
	return ans;
}

int main(){
	long n, m;
	int p, two, five, ans;
	std::cin >> n >> m;
	two = CountTwo(n) - CountTwo(n - m) - CountTwo(m);
	five = CountFive(n) - CountFive(n - m) - CountFive(m);
	ans = std::min(two, five);
	
	std::cout << ans;
}