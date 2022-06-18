#include <iostream>
#include <string>

const int MAX = 5001;
const long long MOD = 1000000;
long long dp[MAX] ={0};

int main(){
	std::string s, offset;
	offset = " ";
	int n, last;
	std::cin >> s;
	if(s[0] == '0'){
		std::cout << 0;
		return 0;
	}
	s = offset + s;
	n = s.length() - 1;
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		if(s[i-1] == '0' && s[i] == '0'){
			std::cout << 0;
			return 0;
		}
		last = (s[i-1] - '0') * 10 + (s[i] - '0');
		if(s[i] - '0' > 0){
			dp[i] = (dp[i-1]) % MOD;
		}
		if(last >= 10 && last < 27){
			dp[i] += dp[i-2] % MOD;
		}
	}
	std::cout << dp[n] % MOD;
}