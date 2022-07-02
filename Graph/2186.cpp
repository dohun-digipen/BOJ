#include <iostream>
#include <string>

int n, m, k, size;
int dx[4] = {0 ,0 ,1 , -1};
int dy[4] = {1, -1, 0 , 0};
int cnt = 0;
std::string s;
char board[100][100];

void DFS(std::string _s, int idx, int x, int y){
	if(board[x][y] != s[idx]){
			return;
		}else{
			if(idx + 1 == size){
				cnt++;
			}
		}
	_s += std::string(1, board[x][y]);
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < 4; j++){
			if(x + (dx[j]*i) >= 0 && x + (dx[j]*i) < n && y + (dy[j]*i) >= 0 && y + (dy[j]*i) < m){
				DFS(_s, idx + 1, x + (dx[j]*i), y + (dy[j]*i));
			}
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m >> k;
	for(int i = 0 ; i < n; i++){
		std::cin >> s;
		for(int j = 0; j < m; j++){
			board[i][j] = s[j];
		}
	}
	std::cin >> s;
	size = s.size();
	
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == s[0]){
				std::string temp;
				DFS(temp, 0, i, j);
			}
		}
	}
	std::cout << cnt;
}