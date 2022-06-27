#include <iostream>
#include <queue>
#include <utility>
#include <string>

const int MAX = 100;
bool maze[MAX][MAX];
bool isVisited[MAX][MAX];
int mazePrice[MAX][MAX] = {0};
std::queue<std::pair<int, int>> path;
int n, m, min;

void BFS(){
	std::pair<int, int> next;
	path.push(std::make_pair(0, 0));
	mazePrice[0][0]++;
	isVisited[0][0] = true;
	while(!path.empty()){
		
		next = path.front();
		path.pop();
		
		if(next.first > 0 && isVisited[next.first - 1][next.second] == false && 
		   maze[next.first - 1][next.second] == true){
			mazePrice[next.first - 1][next.second] = mazePrice[next.first][next.second] + 1;
			path.push(std::make_pair(next.first - 1, next.second));
			isVisited[next.first - 1][next.second] = true;
		}
		
		if(next.first < n  - 1 && isVisited[next.first + 1][next.second] == false && 
		   maze[next.first + 1][next.second] == true){
			mazePrice[next.first + 1][next.second] = mazePrice[next.first][next.second] + 1;
			path.push(std::make_pair(next.first + 1, next.second));
			isVisited[next.first + 1][next.second] = true;
		}
		
		if(next.second > 0 && isVisited[next.first][next.second - 1] == false && 
		   maze[next.first][next.second - 1] == true){
			mazePrice[next.first][next.second - 1] = mazePrice[next.first][next.second] + 1;
			path.push(std::make_pair(next.first, next.second - 1));
			isVisited[next.first][next.second - 1] = true;
		}
		
		if(next.second < m - 1 && isVisited[next.first][next.second + 1] == false && 
		   maze[next.first][next.second + 1] == true){
			mazePrice[next.first][next.second + 1] = mazePrice[next.first][next.second] + 1;
			path.push(std::make_pair(next.first, next.second + 1));
			isVisited[next.first][next.second + 1] = true;
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m;
	for(int i = 0; i < n; i++){
		std::string s;
		std::cin >> s;
		for(int j = 0;  j < m; j++){
			maze[i][j] = s[j] - '0';
		}
	}
	BFS();
	std::cout << mazePrice[n - 1][m - 1];
}