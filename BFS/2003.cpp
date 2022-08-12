#include <iostream>

int arr[10000], n, m, ans;

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m;
	for(int i = 0; i < n; i++){
		std::cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			if(sum == m){
				ans++;
				break;
			}
		}
	}
	std::cout << ans;
}