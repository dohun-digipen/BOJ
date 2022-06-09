#include <iostream>
#include <vector>

int min = 100000000;
int arr[10][10];
bool visited[10];
std::vector<int> path;
int n;
int dst;

int Sum(){
	int sum = 0;
	for(auto i : path){
		std::cout << i << " ";
		sum += i;
	}
	std::cout << "\n";
	return sum;
}

void FindPath(int cnt, int start){
	visited[start] = true;
	if(cnt == n - 1){
		int sum = Sum();
		if(min > sum){
			min = sum;
			dst = start;
		}
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(arr[start][i] != 0 && visited[i] == false){
			path.push_back(arr[start][i]);
			FindPath(cnt + 1, i);
			path.pop_back();
			visited[i] = false;
		}
	}
}

int main(){
	int a;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> a;
			arr[i][j] = a;
		}
		visited[i] = false;
	}
	
	for(int i = 0; i < n; i++){
		FindPath(0, i);
		//std::cout << "s : " << i << " dst : " << dst << "\n"; 
	}
	
	std::cout << min;
}