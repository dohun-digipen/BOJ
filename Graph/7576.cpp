#include <utility>
#include <iostream>
#include <queue>

const int MAX = 1001;
int g[MAX][MAX];
bool isVisited[MAX][MAX];
int m, n, cnt, day;
std::queue<std::pair<int, int>> path;

void ShowG(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			std::cout << g[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void BFS(){
	while(!path.empty()){
		if(cnt == 0){
			day++;
			cnt = path.size();
		}

		std::pair<int, int> next = path.front();
		path.pop();
		cnt--;
		
		if(next.first > 0 && isVisited[next.first - 1][next.second] == false && g[next.first - 1][next.second] == 0){
			path.push(std::make_pair(next.first - 1, next.second));
			g[next.first - 1][next.second] = 1;
			isVisited[next.first - 1][next.second] = true;
		}
		if(next.second < m - 1 && isVisited[next.first][next.second + 1] == false && g[next.first][next.second + 1] == 0){
			path.push(std::make_pair(next.first, next.second + 1));
			g[next.first][next.second + 1] = 1;
			isVisited[next.first][next.second + 1] = true;
		}
		if(next.first < n - 1 && isVisited[next.first + 1][next.second] == false && g[next.first + 1][next.second] == 0){
			path.push(std::make_pair(next.first + 1, next.second));
			g[next.first + 1][next.second] = 1;
			isVisited[next.first + 1][next.second] = true;
		}
		if(next.second > 0 && isVisited[next.first][next.second - 1] == false && g[next.first][next.second - 1] == 0){
			path.push(std::make_pair(next.first, next.second - 1));
			g[next.first][next.second - 1] = 1;
			isVisited[next.first][next.second - 1] = true;
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	day = 0;
	bool flag = false;
	std::cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			std::cin >> g[i][j];
			if(g[i][j] == 1){
				path.push(std::make_pair(i, j));
				isVisited[i][j] = true;
			}
			if(g[i][j] == 0){
				flag = true;
			}
		}
	}
	
	if(flag == false){
		std::cout << 0;
	}else{
		cnt = path.size();
		BFS();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(g[i][j] == 0){
					day = -1;
				}
			}
			if(day == -1){
				break;
			}
		}
		std::cout << day;
	}
}