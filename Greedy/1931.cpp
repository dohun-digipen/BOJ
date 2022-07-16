#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<std::pair<int, int>> vec;
int n, t;

bool Comp(std::pair<int, int> a, std::pair<int, int> b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		vec.push_back(std::make_pair(a, b));
	}
	
	std::sort(vec.begin(), vec.end(), Comp);
	int idx = 0;
	t = 1;
	for(int i = 1; i < vec.size(); i++){
		if(vec[i].first >= vec[idx].second){
			idx = i;
			t++;
		}
	}
	std::cout << t;
}