#include <iostream>
#include <algorithm>
const int MAX = 10001;
int arr[MAX];
int dp[MAX];

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, num;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		std::cin >> num;
		arr[i] = num;
 	}
	
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	
	for(int i = 3; i <= n; i++){
		dp[i] = std::max((dp[i-2] + arr[i]), (dp[i-3] + arr[i-1] + arr[i]));
		dp[i] = std::max(dp[i], dp[i-1]);
	}
	
	std::cout << dp[n];
}