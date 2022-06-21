#include <iostream>
#include <cstring>

const int MAX = 1001;
int g[MAX];
bool isVisited[MAX] = {false};
int t, n, num;

void DFS(int start){
	isVisited[start] = true;
	if(isVisited[g[start]] == false){
		DFS(g[start]);
	}
}

void Reset(){
	memset(isVisited, false, sizeof(isVisited));
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> t;
	for(int i = 0; i < t; i++){
		int ans = 0;
		std::cin >> n;
		for(int j = 1; j <= n; j++){
			std::cin >> g[j];
		}
		for(int j = 1; j <= n; j++){
			if(isVisited[j] == false){
				DFS(j);
				ans++;
			}
		}
		std::cout << ans << "\n";
		Reset();
	}
}