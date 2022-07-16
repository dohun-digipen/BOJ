#include <vector>
#include <iostream>
#include <algorithm>

int n, ans, bound;
bool hasZero = false;
bool isOdd = false;
std::vector<int> arr;

bool Comp(int a, int b){
	return a > b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		std::cin >> temp;
		arr.push_back(temp);
	}
	
	std::sort(arr.begin(), arr.end(), Comp);
	bound = -1;
	
	for(int i = 0; i < n; i++){
		if(arr[i] == 0){
			hasZero = true;
		}else if(arr[i] < 0 && bound == -1){
			isOdd = (n - i) % 2;
			bound = i;
			if(isOdd == true){
				if(hasZero == false){
					ans += arr[i];
					isOdd = false;
				}
			}else{
				i--;
			}
		}else{
			if(bound != -1){
				if(isOdd == true){
					if(i < n - 1){
						ans += arr[i] * arr[i + 1];
					    i++;
					}
				}else{
					ans += arr[i] * arr[i + 1];
					i++;
				}
			}else{
				if(i < n - 1 && (arr[i] > 0 && arr[i + 1] > 0)){
					if(arr[i + 1] == 1){
						ans += arr[i] + arr[i + 1];
						i++;
					}else{
						ans += arr[i] * arr[i + 1];
						i++;
					}
				}else{
					ans += arr[i];
				}
			}
		}
	}
	
	std::cout << ans;
}