#include <iostream>

const int MAX = 2200;
int paper[MAX][MAX], cnt[3], n;

void CountPaper(int n, int x, int y){
	if(n == 1){
		cnt[paper[x][y] + 1]++;
		return;
	}
	int prev = paper[x][y];
	for(int i = x; i < x + n; i++){
		for(int j = y; j < y + n; j++){
			if(prev != paper[i][j]){
				for(int k = 0; k < 3; k++){
					for(int l = 0; l < 3; l++){
						int m = n / 3;
						CountPaper(m, x + (m * k), y + (m * l));
					}
				}
				return;
			}
		}
	}
	cnt[prev + 1]++;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> paper[i][j];
		}
	}
	CountPaper(n, 0, 0);
	for(int i = 0; i < 3; i++){
		std::cout << cnt[i] << "\n";
	}
}