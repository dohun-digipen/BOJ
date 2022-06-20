#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

std::vector<std::vector<int>> g;
bool isVisited[20001] = {false};
bool isColored[20001] = {false};
int k ,v, e;

void BFS(int start){
	std::queue<int> q;
	int next;
	q.push(start);
	isVisited[start] = true;
	while(!q.empty()){
		next = q.front();
		q.pop();
		int len = g[next].size();
		for(int i = 0; i < len; i++){
			if(isVisited[g[next][i]] == false){
				q.push(g[next][i]);
				isVisited[g[next][i]] = true;
				isColored[g[next][i]] = !isColored[next];
			}
		}
	}
}

void Reset(){
	memset(isVisited, false, sizeof(isVisited));
	memset(isColored, false, sizeof(isColored));
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> k;
	for(int i = 0; i < k; i++){
		std::string ans = "YES";
		std::cin >> v >> e;
		for(int j = 0; j < v + 1; j++){
			std::vector<int> nodes;
			g.push_back(nodes);
		}
		for(int j = 0; j < e; j++){
			int v1, v2;
			std::cin >> v1 >> v2;
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		for(int j = 1; j <= v; j++){
			if(isVisited[j] == false){
				BFS(j);
			}
			int len = g[j].size();
			for(int n = 0; n < len; n++){
				if(isColored[j] == isColored[g[j][n]]){
					ans = "NO";
					break;
				}
			}
			if(ans == "NO"){
				break;
			}
		}
		std::cout << ans << "\n";
		g.clear();
		Reset();
	}
}