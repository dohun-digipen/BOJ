#include <iostream>
#include <cstring>

const int MAX = 6200;
char board[MAX][MAX];
int n;

void Dot(int x, int y){
	board[x][y + 2] = '*';
	board[x + 1][y + 1] = '*';
	board[x + 1][y + 3] = '*';
	for(int j = 0; j < 5; j++){
		board[x + 2][y + j] = '*';
	}
}

void MakeBoard(int n, int x, int y){
	if(n == 3){
		Dot(x, y);
		return;
	}
	MakeBoard(n / 2, x, y + (n / 2));
	MakeBoard(n / 2, x + (n / 2), y);
	MakeBoard(n / 2, x + (n / 2), y + n);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	memset(board, ' ', sizeof(board));
	std::cin >> n;
	MakeBoard(n, 0, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n * 2; j++){
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
}