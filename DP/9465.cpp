#include <algorithm>
#include <iostream>
const int MAX_N = 100001;

int dp[2][MAX_N];
int arr[2][MAX_N];

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k, num;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> k;
		for(int j = 1; j <= k; j++){
			std::cin >> num;
			arr[0][j] = num;
		}
		for(int j = 1; j <= k; j++){
			std::cin >> num;
			arr[1][j] = num;
		}
		
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		dp[0][2] = dp[1][1] + arr[0][2];
		dp[1][2] = dp[0][1] + arr[1][2];
		
		for(int i = 3; i <= k; i++){
			dp[0][i] = arr[0][i] + std::max(dp[1][i-1], dp[1][i-2]);
			dp[1][i] = arr[1][i] + std::max(dp[0][i-1], dp[0][i-2]);
		}
		int max = std::max(dp[0][k], dp[1][k]);
		std::cout << max <<"\n";
	}
}