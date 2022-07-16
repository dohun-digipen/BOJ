#include <iostream>

int n, m, k;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m >> k;
	int team = 0;
	while(true){
		if(n - 2 + m - 1 - k >= 0 && n >= 2 && m >= 1){
			n -= 2;
			m -= 1;
			team++;
		}else{
			break;
		}
	}
	std::cout << team;
}