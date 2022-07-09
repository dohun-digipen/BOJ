#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> order;
int n, cnt;

void HnoiMove(int num, int from, int by, int to){
	if(num == 1){
		order.push_back(std::make_pair(from, to));
	}else{
		HnoiMove(num - 1, from, to, by);
		order.push_back(std::make_pair(from, to));
		HnoiMove(num - 1, by, from, to);
	}
	cnt++;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	HnoiMove(n, 1, 2, 3);
	std::cout << cnt << "\n";
	for(int i = 0; i < order.size(); i++){
		std::cout << order[i].first << " " << order[i].second << "\n";
	}
	
}