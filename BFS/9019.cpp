#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>

const int MAX = 10000;
bool isVisited[MAX];
std::string command[4] = {"D", "S", "L", "R"};
std::string ans;
int t, a, b;

int Converter(int n, const std::string& s){
	if(s == "D"){
		if(n * 2 > 9999){
			return (n * 2) % 10000;
		}else{
			return n * 2;
		}
	}else if(s == "S"){
		if(n == 0){
			return 9999;
		}else{
			return n - 1;
		}
	}else if(s == "L"){
		return n % 1000 * 10 + n / 1000;
	}else if(s == "R"){
		return n % 10 * 1000 + n / 10;
	}
	return -1;
}

void BFS(){
	memset(isVisited, false, sizeof(isVisited));
	std::queue<std::pair<int, std::string>> q;
	int curr;
	std::string s;
	q.push(std::make_pair(a, std::string()));
	isVisited[a] = true;
	while(!q.empty()){
		curr = q.front().first;
		s = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int next = Converter(curr, command[i]);
			if(isVisited[next] == false){
				if(next == b){
					ans = s + command[i];
					return;
				}
				q.push(std::make_pair(next, s + command[i]));
				isVisited[next] = true;
			}
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> t;
	for(int i = 0; i < t; i++){
		std::cin >> a >> b;
		BFS();
		std::cout << ans << "\n";
	}
}