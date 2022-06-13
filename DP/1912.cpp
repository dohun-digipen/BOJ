#include <iostream>
#include <algorithm>

const int MAX = 100001;
int arr[MAX];
int dp[MAX];

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int ans;
	int n;
	
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		std::cin >> arr[i];
	}
	
	dp[1] = arr[1];
	ans = dp[1];
	
	for(int i = 2; i <= n; i++){
		if(dp[i-1] + arr[i] > arr[i]){
			dp[i] = dp[i-1] + arr[i];
		}else{
			dp[i] = arr[i];
		}
		ans = std::max(ans, dp[i]);
	}
	
	std::cout << ans;
}