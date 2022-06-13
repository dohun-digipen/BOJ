#include <iostream>
#include <algorithm>

const int MAX = 1001;
int arr[MAX];
int dp[MAX];
int arrReverse[MAX];
int dpReverse[MAX];
 int main(){
	 std::ios_base :: sync_with_stdio(false);
	 std::cin.tie(NULL);
	 std::cout.tie(NULL);
	 
	 int n;
	 int ans = 0;
	 std::cin >> n;
	 
	 for(int i = 1; i <= n; i++){
		 std::cin >> arr[i];
		 arrReverse[n + 1 - i] = arr[i];
	 }
	
	 for(int i = 1; i <= n; i++){
		 dp[i] = 1;
		 dpReverse[i] = 1;
		 for(int j = i - 1; j >= 1; j--){
			 if(arr[i] > arr[j]){
				 dp[i] = std::max(dp[i], dp[j] + 1);
			 }
			 if(arrReverse[i] > arrReverse[j]){
				 dpReverse[i] = std::max(dpReverse[i], dpReverse[j] + 1);
			 }
		 }
	 }
	 for(int i = 1; i <= n; i++){
		 if(ans < dp[i] + dpReverse[n + 1 - i] - 1){
			 ans = dp[i] + dpReverse[n + 1 - i] - 1;
		 }
	 }
	 
	std::cout << ans;
 }