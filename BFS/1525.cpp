#include <iostream>
#include <string>
#include <queue>
#include <utility>
int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
std::string board;

void swap(std::string& s, int x, int y, int sx, int sy){
	char temp = s[y + (x * 3)];
	s[y + (x * 3)] = s[sy + (sx * 3)];
	s[y + (x * 3)] = temp;
}

void BFS(){
	std::queue<std::pair<std::string, int>> q;
	std::string currS;
	int currC;
	q.push(std::make_pair(board, 0));
	while(!q.empty()){
		currS = q.front().first;
		currC = q.front().second;
		for(int i = 0; i < 4; i++){
			
		}
	}
}
int main(){
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			std::cin >> n;
			board += std::to_string(n);
		}
	}
	
	
}