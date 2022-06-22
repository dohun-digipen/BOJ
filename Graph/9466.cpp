#include<iostream>
#include <cstring>
const int MAX = 100001;
int g[MAX];
bool isClosed;
bool isClosed[MAX];
bool isVisited[MAX];
int t, n, ans, srt;

void DFS(int start){
	isVisited[start] = true;
	if(g[start] == srt){
		isClosed = true;
	}
	if(isVisited[g[start]] == false){
		DFS(g[start]);
	}
	if(isClosed == true){
		ans++;
	}else{
		isVisited[start] = false;
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> t;
	for(int i = 0; i < t; i++){
		std::cin >> n;
		ans = 0;
		for(int j = 1; j <= n; j++){
			std::cin >> g[j];
			if(g[j] == j){
				isVisited[j] = true;
				ans++;
			}
		}
		
		for(int j = 1; j <= n; j++){
			srt = j;
			isClosed = false;
			if(isVisited[j] == false){
				DFS(j);
			}
		}
		memset(isVisited, false, sizeof(isVisited));
		std::cout << n - ans << "\n";
	}
}