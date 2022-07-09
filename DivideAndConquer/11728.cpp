#include <iostream>
#include <algorithm>

#define For(i, n) for(int i = 0; i < n; i++)

const int MAX = 2000000;
int n, m, ans[MAX], arr[MAX];
void Sort(int start, int end){
	int mid = (start + end) / 2;
	if(start < end){
		Sort(start, mid);
		Sort(mid + 1, end);
	}
	
	int i, j, k;
	i = start; j = mid + 1; k = start;
	while(i <= mid && j <= end){
		if(ans[i] > ans[j]){
			arr[k] = ans[j];
			j++;
		}else{
			arr[k] = ans[i];
			i++;
		}
		k++;
	}
	
	if(i > mid){
		while(j <= end){
			arr[k] = ans[j];
			j++;
			k++;
		}
	}else{
		while(i <= mid){
			arr[k] = ans[i];
			i++;
			k++;
		}
	}
	
	for (int a = start; a <= end; a++) {
		ans[a] = arr[a];
	}
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m;
	For(i, n + m){
		std::cin >> ans[i];
	}
	Sort(0, n + m - 1);
	For(i, n + m){
		std::cout << ans[i] << " ";
	}
}