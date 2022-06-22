#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool g[25][25] = {false};
bool isVisited[25][25] = {false};
int n, ans;
std::vector<int> h;

void DFS(int i, int j){
	isVisited[i][j] = true;
	ans++;
	//up
	if(i + 1 < 25 && isVisited[i + 1][j] == false){
		if(g[i + 1][j] == true){
			DFS(i + 1, j);
		}
	}
	//down
	if(i > 0 && isVisited[i - 1][j] == false){
		if(g[i - 1][j] == true){
			DFS(i - 1, j);
		}
	}
	//right
	if(j + 1 < 25 && isVisited[i][j + 1] == false){
		if(g[i][j + 1] == true){
			DFS(i, j + 1);
		}
	}
	//left
	if(j > 0 && isVisited[i][j - 1] == false){
		if(g[i][j - 1] == true){
			DFS(i, j - 1);
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::string s;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		for(int j = 0; j < n; j++){
			g[i][j] = s[j] - '0';
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = 0;
			if(g[i][j] == true && isVisited[i][j] == false){
				DFS(i, j);
			}
			if(ans > 0){
				h.push_back(ans);
			}
		}
	}
	std::sort(h.begin(), h.end());
	std::cout << h.size() << "\n";
	for(auto i : h){
		std::cout << i << "\n";
	}
}