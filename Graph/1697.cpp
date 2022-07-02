#include <iostream>
#include <queue>

const int MAX = 200001;
int n, k, t, size;
bool isVisited[MAX] = {false};
std::queue<int> g;

void BFS(int pos){
	int next = pos;
	g.push(pos);
	size = 1;
	isVisited[pos] = true;
	while(next != k){
		if(size == 0){
			t++;
			size = g.size();
		}
		next = g.front();
		g.pop();
		size--;
		if(isVisited[next - 1] == false && next - 1 < MAX && next - 1 >= 0){
			g.push(next - 1);
			isVisited[next - 1] = true;
		}
		if(isVisited[next + 1] == false && next + 1 < MAX && next + 1 >= 0){
			g.push(next + 1);
			isVisited[next + 1] = true;
		}
		if(isVisited[next * 2] == false && next * 2 < MAX && next * 2 >= 0){
			g.push(next * 2);
			isVisited[next * 2] = true;
		}
	}
}

int main(){
	std::cin >> n >> k;
	t = 0;
	BFS(n);
	std::cout << t;
}