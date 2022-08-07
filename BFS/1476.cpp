#include <iostream>

int NextE(int e){
	if(e == 15){
		return 1;
	}
	return e + 1;
}

int NextS(int s){
	if(s == 28){
		return 1;
	}
	return s + 1;
}

int NextM(int m){
	if(m == 19){
		return 1;
	}
	return m + 1;
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int curE = 1;
	int curS = 1;
	int curM = 1;
	int ans = 1;
	int E, S, M;
	
	std::cin >> E >> S >> M;
	
	while(true){
		if((curE == E) && (curS == S) && (curM == M)){
			break;
		}
		curE = NextE(curE);
		curS = NextS(curS);
		curM = NextM(curM);
		ans++;
	}
	
	std::cout << ans;
}