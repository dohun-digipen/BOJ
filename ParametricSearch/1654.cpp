#include <iostream>
#include <vector>
#include <algorithm>

int k, n;
long long ans;
long long mid, start, end;
std::vector<long long> lines;


int CountLine(int lineLen){
	int total = 0;
	for(auto line : lines){
		total += line / lineLen;
	}
	return total;
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> k >> n;
	for(int i = 0; i < k; i++){
		std::cin >> start;
		lines.push_back(start);
	}
	std::sort(lines.begin(), lines.end());
	end = lines[lines.size() - 1];
	start = 1;
	mid = (start + end) / 2;
	ans = 0;
	
	while(end-start>= 0){
		int cnt = CountLine(mid);
		if(cnt >= n){
			start = mid + 1;
			if(mid > ans){
				ans = mid;
			}
		}else if(cnt < n){
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	std::cout << ans;
}