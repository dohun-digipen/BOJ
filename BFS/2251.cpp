#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool isVisited[201][201][201];
bool isInVector[201];
std::vector<int> ans;
int A, B, C;

void DFS(int a, int b, int c){
	if(isVisited[a][b][c] == true){
		return;
	}
	//A가 0인 경우에서도 물통을 옮기는 경우를 생각 해야함 (B, C끼리 옮기는 경우)
	if(a == 0){
		if(isInVector[c] == false){
			ans.push_back(c);
			isInVector[c] = true;
		}
	}
	isVisited[a][b][c] = true;
	//A -> B, C
	if(B < a + b){
		DFS((a + b) - B, B, c);
	}else{
		DFS(0, a + b, c);
	}
	
	if(C < a + c){
		DFS((a + b) - C, b, C);
	}else{
		DFS(0, b, a + c);
	}
	//B -> A, C
	if(b != 0){
		if(A < a + b){
			DFS(A, a + b - A, c);
		}else{
			DFS(a + b, 0, c);
		}
	
		if(C < b + c){
			DFS(a, b + c - C, C);
		}else{
			DFS(a, 0, b + c);
		}
	}
	//C -> A, B
	if(c != 0){
		if(A < a + c){
			DFS(A, b, a + c - A);
		}else{
			DFS(a + c, b, 0);
		}
	
		if(B < b + c){
			DFS(a, B, b + c - B);
		}else{
			DFS(a, b + c, 0);
		}
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> A >> B >> C;
	DFS(0, 0, C);
	if(B > C){
		DFS(0, C, 0);
	}else{
		DFS(0, B, C - B);
	}
	
	if(A > C){
		DFS(C, 0, 0);
	}else{
		DFS(A, 0, C - A);
	}
	std::sort(ans.begin(), ans.end());
	for(auto n : ans){
		std::cout << n << " ";
	}
}