#include <iostream>
int n, k, curIdx, cnt;
bool isVistied[100001] = {false};
int GetNext(int idx){
	if(idx == n){
		return 1;
	}
	return idx + 1;
}

int NextYo(int idx){
	int jump = k;
	int cur = idx;
	while(jump != 0){
		if(isVistied[cur] != true){
			jump--;
		}
		cur = GetNext(cur);
	}
	return cur;
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> k;
	curIdx = k;
	cnt = 0;
	std::cout << "<";
	while(true){
		if(cnt < n - 1){
			std::cout << curIdx << ", ";
		}else{
			std::cout << curIdx << ">";
			break;
		}
		isVistied[curIdx] = true;
		curIdx = NextYo(curIdx);
		cnt++;
	}
}