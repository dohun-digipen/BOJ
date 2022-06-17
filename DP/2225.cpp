#include <iostream>

const int MAX = 201;
const int MOD = 1000000000;

long long dp[MAX][MAX] = {0};

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++){
		dp[i][1] = 1;
	}
	
	for(int i = 1; i <= k; i++){
		dp[1][i] = i;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	
	std::cout << dp[n][k];
}