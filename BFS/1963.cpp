#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <string>

const int MAX = 100000;
bool prime[MAX];
bool isVisited[MAX];
int t, srt, dest, ans;

int ChangeStoI(std::string s, int idx, int n){
	s[idx] = '0' + n;
	return std::stoi(s);
}
void SetPrime(){
	memset(prime, true, sizeof(prime));
	for(int i = 2; i * i < MAX; i++){
		if(prime[i]){
			for(int j = i * i; j < MAX; j += i){
				prime[j] = false;
			}
		}
	}
}

void BFS(){
	bool isPossible = false;
	memset(isVisited, false, sizeof(isVisited));
	std::pair<int, int> curr;
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(srt, 0));
	while(!q.empty()){
		curr = q.front();
		q.pop();
		if(curr.first == dest){
			isPossible = true;
			break;
		}
		std::string s = std::to_string(curr.first);
		for(int i = 0; i < 4; i++){
			int start;
			if(i == 0){
				start = 1;
			}else{
				start = 0;
			}
			for(int j = start; j <= 9; j++){
				if(j != s[i] - '0'){
					int n = ChangeStoI(s, i, j);
					if(prime[n] == true && isVisited[n] == false){
						q.push(std::make_pair(n, curr.second + 1));
						isVisited[n] = true;
					}
				}
			}
		}
	}
	if(isPossible == true){
		ans = curr.second;
	}else{
		ans = -1;
	}
}

int main(){
	std::cin >> t;
	SetPrime();
	for(int i = 0; i < t; i++){
		std::cin >> srt >> dest;
		BFS();
		if(ans == -1){
			std::cout << "Impossible\n";
		}else{
			std::cout << ans << "\n";
		}
	}
}