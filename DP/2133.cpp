#include <iostream>

int dp[31] = {0};
int main(){
	int n;
	std::cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;
	for(int i = 6; i<= n; i+=2){
		dp[i] = dp[i-2] * 3;
		for(int j = i - 4; j >= 0; j -= 2){
			dp[i] += dp[j] * 2;
		}
	}
	
	std::cout << dp[n];
}