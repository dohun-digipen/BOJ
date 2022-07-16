#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
int n, ans;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		vec.push_back(a);
	}
	
	std::sort(vec.begin(), vec.end());
	int len = vec.size();
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j <= i; j++){
			ans += vec[j];
		}
	}
	std::cout << ans;
}