#include <iostream>
#include <queue>
bool g[1001][1001] = {false};
bool isVisited[1001] = {false};
int u, v, n, m;

void DFS(int start){
	isVisited[start] = true;
	for(int i = 1; i <= n; i++){
		if(isVisited[i] == false && g[start][i] == true){
			DFS(i);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int ans = 0;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		g[u][v] = true;
		g[v][u] = true;
	}
	for(int i = 1; i <= n; i++){
		if(isVisited[i] == false){
			std::queue<int> q;
			isVisited[i] = true;
			q.push(i);
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(int j = 1; j <= n; j++){
					if(isVisited[j] == false && g[node][j] == true){
						isVisited[j] = true;
						q.push(j);
					}
				}
			}
			ans++;
		}
	}
	std::cout << ans;
}