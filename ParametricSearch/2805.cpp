#include <iostream>

const int MAX = 1000000;
int arr[MAX];
int n, m;

bool Check(int cut){
	long long total = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] - cut > 0){
			total += arr[i] - cut;
		}
	}
	if(total >= m){
		return true;
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int lo, mid, hi;
	int max = 0;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++){
		std::cin >> arr[i];
		if(arr[i] > max){
			max = arr[i];
		}
	}
	
	lo = 0;
	hi = max;
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(Check(mid) == true){
			lo = mid;
		}else{
			hi = mid;
		}
	}
	std::cout << lo;
}