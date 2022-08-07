#include <iostream>

int Factorial(int n){
	if(n == 1 || n == 0){
		return 1;
	}
	return Factorial(n - 1) * n;
}

int Count(int one, int two, int three){
	int count = 0;
	count = Factorial(one + two + three) / (Factorial(one) * Factorial(two) * Factorial(three));
	return count;
}

int main(){
	int n, num, i, j, k;
	int ans = 0;
	std::cin >> n;
	for(int loop = 0; loop < n; loop++){
		std::cin >> num;
		ans = 0;
		i = num;
		j = num / 2;
		k = num / 3;
		
		for(int one = 0; one <= i; one++){
			for(int two = 0; two <= j; two++){
				for(int three = 0; three <= k; three++){
					if(num == one + (two * 2) + (three * 3)){
						ans += Count(one, two, three);
					}
				}
			}
		}
		std::cout << ans << "\n";
	}
}