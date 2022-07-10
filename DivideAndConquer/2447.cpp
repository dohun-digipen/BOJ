#include <iostream>
char star[2200][2200];

void Dot(bool isStar, int x, int y){
	if(isStar == true){
		for(int i = x; i < x + 3; i++){
			for(int j = y; j < y + 3; j++){
				if(i == x + 1 && j ==  y + 1){
					star[i][j] = ' ';
				}else{
					star[i][j] = '*';
				}
			}
		}
	}else{
		for(int i = x; i < x + 3; i++){
			for(int j = y; j < y + 3; j++){
				star[i][j] = ' ';
			}
		}
	}
}

void Star(int n, bool isStar, int x, int y){
	if(n == 3){
		Dot(isStar, x, y);
		return;
	}
	int m = n / 3;
	
	for(int k = 0; k < 3; k++){
		for(int l = 0; l < 3; l++){
			if(isStar == true){
				if(k == 1 && l == 1){
					Star(m, false, x + (m * k), y + (m * l));
				}else{
					Star(m, true, x + (m * k), y + (m * l));
				}
			}else{
				Star(m, false, x + (m * k), y + (m * l));
			}
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	Star(n, true, 0, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << star[i][j];
		}
		std::cout << "\n";
	}
}