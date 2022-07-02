#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

const int MAX = 100;
int map[MAX][MAX];
int cost[MAX][MAX];
std::queue<std::pair<int, int>> path;
bool isVisited[MAX][MAX];
int n, min;
int landNum = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y){
	std::pair<int, int> next;
	path.push(std::make_pair(x, y));
	isVisited[x][y] = true;
	bool isFound = false;
	while(!path.empty()){
		next = path.front();
		path.pop();
		if(map[next.first][next.second] > 0 && 
		   map[next.first][next.second] != map[x][y]){
			if(min > cost[next.first][next.second] - 1){
				min = cost[next.first][next.second] - 1;
			}
		}
		for(int k = 0; k < 4; k++){
			if((next.first + dx[k] >= 0 && next.first + dx[k] < n) && 
			   (next.second + dy[k] >= 0 && next.second + dy[k] < n) && 
			   isVisited[next.first + dx[k]][next.second + dy[k]] == false){
				path.push(std::make_pair(next.first + dx[k], next.second + dy[k]));
				isVisited[next.first + dx[k]][next.second + dy[k]] = true;
				cost[next.first + dx[k]][next.second + dy[k]] = cost[next.first][next.second] + 1;
			}
		}
	}
}

void DFS(int x, int y){
	map[x][y] = landNum;
	isVisited[x][y] = true;
	for(int k = 0; k < 4; k++){
		if((x + dx[k] >= 0 && x + dx[k] < n) && (y + dy[k] >= 0 && y + dy[k] < n)){
			if(map[x + dx[k]][y + dy[k]] == 1 && isVisited[x + dx[k]][y + dy[k]] == false){
				DFS(x + dx[k], y + dy[k]);
			}
		}
	}
}

void ShowInfo(){
	std::cout << "=======================\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	min = 10000;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] != 0 && isVisited[i][j] == false){
				landNum++;
				DFS(i, j);
			}
		}
	}
	//ShowInfo();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] > 0){
				for(int k = 0; k < 4; k++){
					if((i + dx[k] >= 0 && i + dx[k] < n) && (j + dy[k] >= 0 && j + dy[k] < n)){
						if(map[i + dx[k]][j + dy[k]] == 0){
							//각 섬의 모든 edge에 대해서 탐색 진행
							path = std::queue<std::pair<int, int>>();
							memset(isVisited, false, sizeof(isVisited));
							memset(cost, 0, sizeof(cost));
							BFS(i, j);
							break;
						}
					}
				}
			}
		}
	}
	
	std::cout << min;
}