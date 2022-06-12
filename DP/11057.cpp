#include <iostream>

int dp[1001][10] = {0};
int n;
int ans = 0;
const int MOD = 10007;
int main(){
	std::cin >> n;
	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= j; k++){
				dp[i][j] += dp[i-1][k]; 
			}
			dp[i][j] %= MOD;
		}
	}
	
	for(int j = 0; j < 10; j++){
		ans = (ans + dp[n][j]) % MOD;
	}
	std::cout << ans;
}