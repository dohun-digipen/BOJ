#include <iostream>
#include <string>
#include <cstring>

int n, m, k, size;
int dx[4] = {0 ,0 ,1 , -1};
int dy[4] = {1, -1, 0 , 0};
int dp[100][100][80];
int cnt = 0;
std::string s;
char board[100][100];

int DFS(int idx, int x, int y){
	if(dp[x][y][idx] != -1){
		return dp[x][y][idx];
	}
	if(idx >= size){
		return 1;
	}
	dp[x][y][idx] = 0;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < 4; j++){
			if(x + (dx[j]*i) >= 0 && x + (dx[j]*i) < n && y + (dy[j]*i) >= 0 && y + (dy[j]*i) < m){
				if(board[x + (dx[j]*i)][y + (dy[j]*i)] == s[idx]){
					dp[x][y][idx] += DFS(idx + 1, x + (dx[j]*i), y + (dy[j]*i));
				}
			}
		}
	}
	return dp[x][y][idx];
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
	memset(dp, -1, sizeof(dp));
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == s[0]){
				cnt += DFS(1, i, j);
			}
		}
	}
	std::cout << cnt;
}