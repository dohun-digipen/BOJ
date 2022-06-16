#include <iostream>
#include <algorithm>
const int MAX = 1001;
long long arr[MAX];
long long dp[MAX];

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		std::cin >> arr[i];
	}
	
	dp[0] = 0;
	dp[1] = arr[1];
	
	long long max = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			max = std::max(max, dp[i - j] + dp[j]);
		}
		if(max < arr[i]){
			max = arr[i];
		}
		dp[i] = max;
	}
	std::cout << dp[n];
}