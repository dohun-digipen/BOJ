#include <iostream>
#include <algorithm>
int dp[1001];
int n;
int main(){
	std::cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for(int i = 3; i <= n; i++){
		dp[i] = (dp[i  - 1] + (dp[i - 2] * 2)) % 10007;
	}
	std::cout << dp[n];
}