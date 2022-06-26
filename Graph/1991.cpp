#include <iostream>
#include <cstring>

const int MAX = 26 * 3;
int tree[MAX] = {-1};
bool isVisited[MAX];
int n;


void PreOrder(int idx){
	isVisited[idx] = true;
	std::cout << char('A' + idx);
	if(tree[idx * 2] != -1 && isVisited[tree[idx * 2]] == false){
		PreOrder(tree[idx * 2]);
	}
	if(tree[(idx * 2) + 1] != -1 && isVisited[tree[(idx * 2) + 1]] == false){
		PreOrder(tree[(idx * 2) + 1]);
	}
}

void InOrder(int idx){
	if(tree[idx * 2] != -1 && isVisited[tree[idx * 2]] == false){
		InOrder(tree[idx * 2]);
	}
	isVisited[idx] = true;
	std::cout << char('A' + idx);
	if(tree[(idx * 2) + 1] != -1 && isVisited[tree[(idx * 2) + 1]] == false){
		InOrder(tree[(idx * 2) + 1]);
	}
}

void PostOrder(int idx){
	if(tree[idx * 2] != -1 && isVisited[tree[idx * 2]] == false){
		PostOrder(tree[idx * 2]);
	}
	if(tree[(idx * 2) + 1] != -1 && isVisited[tree[(idx * 2) + 1]] == false){
		PostOrder(tree[(idx * 2) + 1]);
	}
	isVisited[idx] = true;
	std::cout << char('A' + idx);
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	char rightNode, leftNode, cur;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> cur >> leftNode >> rightNode;
		int idx;
		if(leftNode != '.'){
			idx = leftNode - 'A';
			tree[idx * 2] = idx;
		}
		if(rightNode != '.'){
			idx = rightNode - 'A';
			tree[(idx * 2) + 1] = idx;
		}
	}
	
	PreOrder(0);
	memset(isVisited, false, sizeof(isVisited));
	std::cout << "\n";
	InOrder(0);
	memset(isVisited, false, sizeof(isVisited));
	std::cout << "\n";
	PostOrder(0);
}