#include <iostream>

int n, m, k;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m >> k;
	int gMod, bMod, team;
	if(n >= 2 && m >= 1){
		team = n / 2;
		while(team > 0){
			if(m / team > 0){
				gMod = n - (team * 2);
				bMod = m - team;
				if(gMod + bMod - k >= 0){
					break;
				}else{
					team--;
				}
			}
		}
		std::cout << team;
	}else{
		std::cout << 0;
	}
}