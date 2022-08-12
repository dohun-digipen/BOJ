#include <iostream>

int nums[13], k, ans[6];

void DFS(int idx, int cnt){
	if(cnt == 6){
		for(int i = 0; i < 6; i++){
			std::cout << ans[i] << " ";
		}
		std::cout << "\n";
		return;
	}
	for(int i = idx; i < k; i++){
		ans[cnt] = nums[i];
		DFS(i + 1, cnt + 1);
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	while(true){
		std::cin >> k;
		if(k == 0){
			break;
		}
		for(int i = 0; i < k; i++){
			std::cin >> nums[i];
		}
		DFS(0, 0);
		std::cout << "\n";
	}
}