#include <iostream>
#include <cmath>
#include <vector>
const int MAX = 100001;
int dp[MAX];
std::vector<int> sqrts;

bool IsSquare(unsigned int num){
	unsigned int temp = (unsigned int)(std::sqrt((double)num)+0.5);
	return temp*temp == num;
}

int main(){
	int n, temp;
	std::cin >> n;
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		if(IsSquare(i) == true){
			sqrts.push_back(i);
			dp[i] = 1;
		}else{
			dp[i] = MAX;
			for(auto sqrt : sqrts){
				temp = i / sqrt;
				dp[i] = std::min(dp[i], dp[i % sqrt] + temp);
			}
		}
	}
	std::cout << dp[n];
}