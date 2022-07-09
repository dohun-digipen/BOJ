#include <iostream>
#include <algorithm>

const int MAX = 200000;
int n, c, house[MAX];

int BS(){
	int lo, hi, cnt, mid, ans;
	lo = 1;
	hi = house[n - 1] - house[0];
	ans = 0;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		cnt = 1;
		int prev = house[0];
		for(int i = 1; i < n; i++){
			if(mid <= house[i] - prev){
				cnt++;
				prev = house[i];
			}
		}
		if(cnt >= c){
			lo = mid + 1;
			if(ans < mid){
				ans = mid;
			}
		}else{
			hi = mid - 1;
		}
		
	}
	return ans;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> c;
	for(int i = 0; i < n; i++){
		std::cin >> house[i];
	}
	std::sort(house, house + n);
	std::cout << BS();
}