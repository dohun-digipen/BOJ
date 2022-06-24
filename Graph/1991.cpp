#include <iostream>
#include <cstring>
#include <string>
class Node{
public:
	Node(char _name, Node* _left, Node* _right){
		std::cout << 
		name = _name;
		left = _left;
		right = _right;
	}
	char name;
	Node* left;
	Node* right;
};

const int MAX = 27;
Node* tree[MAX];
bool isVisited[MAX];
int n;


void PreOrder(Node* curNode){
	int idx = curNode->name - 'A';
	isVisited[idx] = true;
	std::cout << curNode->name;
	if(curNode->left != nullptr){
		PreOrder(curNode->left);
	}
	if(curNode->right != nullptr){
		PreOrder(curNode->right);
	}
}

void InOrder(Node* curNode){
	int idx = curNode->name - 'A';
	if(curNode->left != nullptr){
		InOrder(curNode->left);
	}
	isVisited[idx] = true;
	std::cout << curNode->name;
	if(curNode->right != nullptr){
		InOrder(curNode->right);
	}
}

void PostOrder(Node* curNode){
	int idx = curNode->name - 'A';
	if(curNode->left != nullptr){
		PostOrder(curNode->left);
	}
	if(curNode->right != nullptr){
		PostOrder(curNode->right);
	}
	isVisited[idx] = true;
	std::cout << curNode->name;
}

int main(){
	//std::ios_base :: sync_with_stdio(false);
	//std::cin.tie(NULL);
	//std::cout.tie(NULL);
	
	char rightNode, leftNode, cur;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		char c = 'A' + i;
		tree[n] = new Node('A' + n, nullptr, nullptr);
	}
	for(int i = 0; i < n; i++){
		std::cin >> cur >> leftNode >> rightNode;
		int idx = cur - 'A';
		Node* curNode = tree[idx];
		if(leftNode != '.'){
			idx = leftNode - 'A';
			curNode->left = tree[idx];
		}
		if(rightNode != '.'){
			idx = rightNode - 'A';
			curNode->right = tree[idx];
		}
	}
	
	PreOrder(tree[0]);
	memset(isVisited, false, sizeof(isVisited));
	std::cout << "\n";
	InOrder(tree[0]);
	memset(isVisited, false, sizeof(isVisited));
	std::cout << "\n";
	PostOrder(tree[0]);
}