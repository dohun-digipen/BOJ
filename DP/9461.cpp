#include <iostream>

long long dp[101];
int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, p;
	std::cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for(int i = 0; i < n; i++){
		std::cin >> p;
		for(int j = 6; j <= p; j++){
			dp[j] = dp[j-1] + dp[j-5];
		}
		std::cout << dp[p] << "\n";
	}
}