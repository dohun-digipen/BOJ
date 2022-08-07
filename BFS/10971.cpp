#include <iostream>
#include <vector>

int min = 1e9;
int arr[10][10];
bool visited[10];
std::vector<int> path;
int n;

int Sum(){
	int sum = 0;
	for(int i = 0; i < n - 1; i++){
		if(arr[path[i]][path[i + 1]] == 0){
			return sum = 1e9;
		}
		sum += arr[path[i]][path[i + 1]];
	}
	if(arr[path.back()][path[0]] == 0){
		return 1e9;
	}
	sum += arr[path.back()][path[0]];
	return sum;
}

void FindPath(int cnt){
	
	if(cnt == n){
		int sum = Sum();
		if(sum < min){
			min = sum;
		}
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(visited[i] == false){
			visited[i] = true;
			path.push_back(i);
			FindPath(cnt + 1);
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
	
	FindPath(0);
	
	std::cout << min;
}