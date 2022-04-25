#include <iostream>
int main(){
	int max = -1000000;
	int min = 1000000;
	int n,m;
	 std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> m;
		
		if(m > max){
			max = m;
		}
		
		if(m < min){
			min = m;
		}
	}
	
	std::cout << min << " " << max << "\n";
}