#include <iostream>
#include <cmath>
const int MAX = 100001;
int dp[MAX];

bool IsSquare(unsigned int num){
	unsigned int temp = (unsigned int)(std::sqrt((double)num)+0.5);
	return temp*temp == num;
}

int main(){
	int n;
	int sqrt;
	std::cin >> n;
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		if(IsSquare(i) == true){
			sqrt = i;
			dp[i] = 1;
		}else{
			int temp = i / sqrt;
			dp[i] = dp[i % sqrt] + temp;
		}
	}
	std::cout << n/sqrt << " " << n % sqrt << " " << dp[n];
}