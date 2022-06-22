#include <iostream>
#include <cstring>
bool g[50][50];
bool isVisited[50][50];
int h, w, ans;

void DFS(int i, int j){
	isVisited[i][j] = true;
	//up right
	if(i + 1 < 50 && j + 1 < 50 && isVisited[i + 1][j + 1] == false){
		if(g[i + 1][j + 1] == true){
			DFS(i + 1, j + 1);
		}
	}
	//up left
	if(i + 1 < 50 && j > 0 && isVisited[i + 1][j - 1] == false){
		if(g[i + 1][j - 1] == true){
			DFS(i + 1, j - 1);
		}
	}
	//down right
	if(i > 0 && j + 1 < 50 && isVisited[i - 1][j + 1] == false){
		if(g[i - 1][j + 1] == true){
			DFS(i - 1, j + 1);
		}
	}
	// down left
	if(i > 0 && j > 0 && isVisited[i - 1][j - 1] == false){
		if(g[i - 1][j - 1] == true){
			DFS(i - 1, j - 1);
		}
	}
	//up
	if(i + 1 < 50 && isVisited[i + 1][j] == false){
		if(g[i + 1][j] == true){
			DFS(i + 1, j);
		}
	}
	//down
	if(i > 0 && isVisited[i - 1][j] == false){
		if(g[i - 1][j] == true){
			DFS(i - 1, j);
		}
	}
	//right
	if(j + 1 < 50 && isVisited[i][j + 1] == false){
		if(g[i][j + 1] == true){
			DFS(i, j + 1);
		}
	}
	//left
	if(j > 0 && isVisited[i][j - 1] == false){
		if(g[i][j - 1] == true){
			DFS(i, j - 1);
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	while(true){
		std::cin >> w >> h;
		if(h == 0 && w == 0){
			break;
		}
		ans = 0;
		memset(isVisited, false, sizeof(isVisited));
		memset(g, false, sizeof(g));
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				std::cin >> g[i][j];
			}
		}
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(g[i][j] == true && isVisited[i][j] == false){
					ans++;
					DFS(i, j);
				}
			}
		}
		std::cout << ans << "\n";
	}
}