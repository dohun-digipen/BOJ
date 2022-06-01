#include <iostream>
#include <algorithm>

struct vec{
	int x;
	int y;
};

bool compare(vec a, vec b){
	if(a.y < b.y){
		return true;
	}else if(a.y == b.y){
		if(a.x < b.x){
			return true;
		}
		return false;
	}
	return false;
}

int main(){
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n,x,y;
	vec arr[100000];
	std::cin >> n;
	for(int i = 0; i < n; i++){
		vec a;
		std::cin >> x >> y;
		a.x = x;
		a.y = y;
		arr[i] = a;
	}
	std::sort(arr, arr + n, compare);
	
	for(int i = 0; i < n; i++){
		std::cout << arr[i].x << " " << arr[i].y << "\n";
	}
}