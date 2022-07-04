#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> cards;

bool BS(int num){
	int lo, hi, mid;
	lo = 0;
	hi = cards.size() - 1;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		if(cards[mid] == num){
			return true;
		}
		if(cards[mid] < num){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int temp;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> temp;
		cards.push_back(temp);
	}
	std::sort(cards.begin(), cards.end());
	std::cin >> m;
	for(int i = 0; i < m; i++){
		std::cin >> temp;
		std::cout << BS(temp) << " ";
	}
}