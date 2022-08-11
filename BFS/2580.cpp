#include <iostream>
#include <vector>
#include <string>

struct Point{
	int x;
	int y;
};

int board[9][9];
std::vector<Point> emptyBlock;

bool Check(Point p, int n){
	for(int i = 0; i < 9; i++){
		if(n == board[i][p.y]){
			return false;
		}
	}
	
	for(int i = 0; i < 9; i++){
		if(n == board[p.x][i]){
			return false;
		}
	}
	
	int x = p.x / 3;
	int y = p.y / 3;
	
	for(int i = x * 3; i < (x * 3) + 3; i++){
		for(int j = y * 3; j < (y * 3) + 3; j++){
			if(n == board[i][j] && i != p.x && j != p.y){
				return false;
			}
		}
	}
	
	return true;
}

void DFS(int idx){
	if(idx == emptyBlock.size()){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				std::cout << board[i][j] << " ";
			}
			std::cout << "\n";
		}
		exit(0);
	}
	
	for(int i = 1; i < 10; i++){
		if(Check(emptyBlock[idx], i) == true){
			board[emptyBlock[idx].x][emptyBlock[idx].y] = i;
			DFS(idx + 1);
		}
	}
	board[emptyBlock[idx].x][emptyBlock[idx].y] = 0;
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			std::cin >> n;
			board[i][j] = n;
			if(n == 0){
				Point p{i, j};
				emptyBlock.push_back(p);
			}
		}
	}
	DFS(0);
}