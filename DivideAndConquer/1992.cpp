#include <iostream>
#include <string>
const int MAX = 64;
int n, data[MAX][MAX];
std::string s;
void CompressData(int num, int x, int y){
	if(num == 1){
		std::cout << data[x][y];
		return;
	}
	
	int prev = data[x][y];
	for(int i = x; i < x + num; i++){
		for(int j = y; j < y + num; j++){
			if(prev != data[i][j]){
				int m = num / 2;
				std::cout << "(";
				for(int k = 0; k < 2; k++){
					for(int l = 0; l < 2; l++){
						CompressData(m, x + (m * k), y + (m * l));
					}
				}
				std::cout << ")";
				return;
			}
		}
	}
	std::cout << prev;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		for(int j = 0; j < n; j++){
			data[i][j] = s[j] - '0';
		}
	}
	CompressData(n, 0, 0);
}