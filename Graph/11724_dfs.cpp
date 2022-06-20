#include <iostream>
#include <stack>
bool g[1001][1001] = {false};
bool isVisited[1001] = {false};
int u, v, n, m;
std::stack<int> path;

void DFS(int start){
	isVisited[start] = true;
	for(int i = 1; i <= n; i++){
		if(isVisited[i] == false && g[start][i] == true){
			DFS(i);
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
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
			DFS(i);
			ans++;
		}
	}
	std::cout << ans;
}