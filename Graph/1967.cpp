#include <iostream>
#include <vector>
#include <cstring>

#define MAX 10001

int u, v, n;
std::vector<std::pair<int ,int>> tree[MAX];
bool isVisited[MAX] = {false};
int max = 0;
int ans = 0;
int maxNode = 0;

void DFS(int node, int len){
	if(isVisited[node] == true){
		return;
	}
	
	isVisited[node] = true;
	if(len > max){
		max = len;
		maxNode = node;
	}
	
	for(auto next : tree[node]){
		DFS(next.first, len + next.second);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int m, k, e;
	std::cin >> n;
	for(int i = 0; i < n - 1; i++){
		std::cin >> m >> k >> e;
		tree[m].push_back(std::make_pair(k, e));
		tree[k].push_back(std::make_pair(m, e));
	}
	DFS(1, 0);
	max = 0;
	memset(isVisited, false, sizeof(isVisited));
	DFS(maxNode, 0);
	ans += max;
	std::cout << ans;
}