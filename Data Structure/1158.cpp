#include <iostream>
#include <queue>

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::queue<int> yo;
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++){
		yo.push(i + 1);
	}
	std::cout << "<";
	while(true){
		for(int i = 0; i < k - 1; i++){
			yo.push(yo.front());
			yo.pop();
		}
		if(yo.size() == 1){
			std::cout << yo.front() << ">";
			break;
		}else{
			std::cout << yo.front() << ", ";
			yo.pop();
		}
	}
}