#include <iostream>
long dp[91][2] = {0};
int n;
long ans = 0;
int main(){
	std::cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	ans = dp[n][0] + dp[n][1];
	std::cout << ans;
}