#include <iostream>
#include <vector>

const int MAX = 100001;
std::vector<int> g[MAX];
int p[MAX];
bool isVisited[MAX];
int n;

void DFS(int start){
	isVisited[start] = true;
	for(auto i : g[start]){
		if(isVisited[i] == false){
			p[i] = start;
			DFS(i);
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int u, v;
	std::cin >> n;
	for(int i = 0; i <= n; i++){
		g[i] = std::vector<int>();
	}
	
	for(int i = 1; i < n; i++){
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	DFS(1);
	
	for(int i = 2; i <= n; i++){
		std::cout << p[i] << "\n";
	}
}