#include <iostream>

int dp[101][10];
int n;
int ans = 0;
int main(){
	std::cin >> n;
	dp[1][0] = 0;
	for(int i = 1; i < 10; i++){
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				dp[i][j] = dp[i-1][j+1];
			}else if(j == 9){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			}
			dp[i][j] %= 1000000000;
		}
	}
	
	for(int j = 0; j < 10; j++){
		ans = (ans + dp[n][j]) % 1000000000;
	}
	std::cout << ans;
}