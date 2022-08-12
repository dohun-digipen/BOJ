#include <iostream>
#include <vector>
#include <string>

char board[20][20];
bool isVisited[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c, ans;

void DFS(int x, int y, int cnt){
	if(isVisited[int(board[x][y] - 'A')] == true){
		if(ans < cnt){
			ans = cnt;
		}
		return;
	}
	isVisited[board[x][y] - 'A'] = true;
	for(int  i = 0; i < 4; i++){
		if(x + dx[i] >= 0 && x + dx[i] < r && y + dy[i] >= 0 && y + dy[i] < c){
			DFS(x + dx[i], y + dy[i], cnt + 1);
		}
	}
	isVisited[int(board[x][y] - 'A')] = false;
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::string s;
	std::cin >> r >> c;
	for(int i = 0; i < r; i++){
		std::cin >> s;
		for(int j = 0; j < c; j++){
			board[i][j] = s[j];
		}
	}
	
	DFS(0, 0, 0);
	
	std::cout << ans;
}