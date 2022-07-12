#include <iostream>
#include <vector>

std::vector<int> coin;
int n, k, ans, last;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> k;
	for(int i = 0; i < n; i++){
		int temp;
		std::cin >> temp;
		coin.push_back(temp);
	}
	
	last = coin.size() - 1;
	ans = 0;
	
	while(k != 0){
		for(int i = last; i >= 0; i--){
			if((k / coin[i]) > 0){
				ans += (k / coin[i]);
				k = k % coin[i];
				last = i;
				break;
			}
		}
	}
	
	std::cout << ans;
}