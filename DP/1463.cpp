#include <iostream>
#include <algorithm>
int dp[1000001];
int n;
int main(){
	std::cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4; i <= n; i++){
		if(i % 2 != 0 && i % 3 != 0){
			dp[i] = dp[i-1] + 1;
		}else if(i % 2 == 0 && i % 3 == 0){
			dp[i] = std::min(dp[i/2], dp[i/3]) + 1;
		}
		else if(i % 2 == 0){
			dp[i] = std::min(dp[i-1], dp[i/2]) + 1;
		}else if(i % 3 == 0){
			dp[i] = std::min(dp[i-1], dp[i/3]) + 1;
		}
	}
	std::cout << dp[n];
}