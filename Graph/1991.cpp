#include <iostream>
#include <cstring>

const int MAX = 52;
int tree[MAX] = {-1};
bool isVisited[MAX] ={false};
int n;


void PreOrder(int idx){
	if(idx == -1){
		return;
	}else{
		std::cout << char('A' + idx);
		PreOrder(tree[idx * 2]);
		PreOrder(tree[(idx * 2) + 1]);
	}
}

void InOrder(int idx){
	if(idx == -1){
		return;
	}else{
		InOrder(tree[idx * 2]);
		std::cout << char('A' + idx);
		InOrder(tree[(idx * 2) + 1]);
	}
}

void PostOrder(int idx){
	if(idx == -1){
		return;
	}else{
		PostOrder(tree[idx * 2]);
		PostOrder(tree[(idx * 2) + 1]);
		std::cout << char('A' + idx);
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	memset(tree, -1, sizeof(tree));
	
	char rightNode, leftNode, cur;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> cur >> leftNode >> rightNode;
		int idx;
		int curIdx = cur - 'A';
		if(leftNode != '.'){
			idx = leftNode - 'A';
			tree[curIdx * 2] = idx;
		}
		if(rightNode != '.'){
			idx = rightNode - 'A';
			tree[(curIdx * 2) + 1] = idx;
		}
	}
	
	PreOrder(0);
	std::cout << "\n";
	InOrder(0);
	std::cout << "\n";
	PostOrder(0);
}