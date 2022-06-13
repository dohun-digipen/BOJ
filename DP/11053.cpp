#include <iostream>
#include <algorithm>

const int MAX = 1001;
int arr[MAX];
int dp[MAX];
 int main(){
	 std::ios_base :: sync_with_stdio(false);
	 std::cin.tie(NULL);
	 std::cout.tie(NULL);
	 
	 int n;
	 int ans = 0;
	 std::cin >> n;
	 
	 for(int i = 1; i <= n; i++){
		 std::cin >> arr[i];
	 }
	
	 for(int i = 1; i <= n; i++){
		 dp[i] = 1;
		 for(int j = i - 1; j >= 1; j--){
			 if(arr[i] > arr[j]){
				 dp[i] = std::max(dp[i], dp[j] + 1);
			 }
		 }
		 ans = std::max(dp[i], ans);
	 }
	 std::cout << ans;
 }