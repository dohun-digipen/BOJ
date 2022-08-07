#include <iostream>
#include <queue>
#include <utility>

bool isVisited[1000001];
std::queue<std::pair<int, int>> g;
int F, S, G, U, D;
bool flag;

void BFS(){
	std::pair<int, int> curr;
	isVisited[S] = true;
	g.push(std::make_pair(S, 0));
	while(!g.empty()){
		curr = g.front();
		g.pop();
		if(curr.first == G){
			std::cout << curr.second;
			flag = true;
			return;
		}
		if(curr.first - D > 0 && isVisited[curr.first - D] == false){
			g.push(std::make_pair(curr.first - D, curr.second + 1));
			isVisited[curr.first - D] = true;
		}
		if(curr.first + U <= F && isVisited[curr.first + U] == false){
			g.push(std::make_pair(curr.first + U, curr.second + 1));
			isVisited[curr.first + U] = true;
		}
	}
}

int main(){
	std::cin >> F >> S >> G >> U >> D;
	BFS();
	if(flag == false){
		std::cout << "use the stairs"; 
	}
}
