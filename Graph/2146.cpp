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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y){
	std::pair<int, int> next;
	path.push(std::make_pair(x, y));
	isVisited[x][y] = true;
	bool isFound = false;
	while(!isFound){
		next = path.front();
		path.pop();
		for(int k = 0; k < 4; k++){
			if((next.first + dx[k] >= 0 && next.first + dx[k] < n) && 
			   (next.second + dy[k] >= 0 && next.second + dy[k] < n) && 
			   isVisited[next.first + dx[k]][next.second + dy[k]] == false){
				if(map[next.first + dx[k]][next.second + dy[k]] > 0){
					if(map[next.first + dx[k]][next.second + dy[k]] != map[x][y]){
						if(min > cost[next.first][next.second]){
							min = cost[next.first][next.second];
						}
						isFound = true;
						break;
					}
				}else{
					path.push(std::make_pair(next.first + dx[k], next.second + dy[k]));
					isVisited[next.first + dx[k]][next.second + dy[k]] = true;
					cost[next.first + dx[k]][next.second + dy[k]] = cost[next.first][next.second] + 1;
				}
			}
		}
	}
}

void ShowInfo(){
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
	int landNum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int num;
			std::cin >> num;
			if(num > 0){
				//각각의 섬 구분
				for(int k = 0; k < 4; k++){
					if((i + dx[k] >= 0 && i + dx[k] < n) && (j + dy[k] >= 0 && j + dy[k] < n)){
						if(map[i + dx[k]][j + dy[k]] > 0){
							map[i][j] = map[i + dx[k]][j + dy[k]];
							break;
						}
					}
				}
				if(map[i][j] == 0){
					landNum++;
					map[i][j] = landNum;
				}
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
							//각 섬의 모든 해안가 칸에 대해서 탐색 진행
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