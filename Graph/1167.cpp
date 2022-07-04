#include <iostream>
#include <vector>
#include <cstring>

#define MAX 100001

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
	
	int p, c, cost;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> p;
		while(true){
			std::cin >> c;
			if(c == -1){
				break;
			}
			std::cin >> cost;
			tree[p].push_back(std::make_pair(c, cost));
			tree[c].push_back(std::make_pair(p, cost));
		}
	}
	DFS(1, 0);
	max = 0;
	memset(isVisited, false, sizeof(isVisited));
	DFS(maxNode, 0);
	ans += max;
	std::cout << ans;
}