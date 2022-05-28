#include <iostream>
#include <cmath>
#include <string>
#include <stack>
//스택의 구조를 활용하여 변수를 저장하면 더 코드 줄수를 줄일수있다.
int main(){
	int A, B, n, num;
	int sum = 0;
	std::stack<int> ans;
	std::cin >> A >> B;
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> num;
		sum += num * std::pow(A, n - i - 1);
	}
	
	while(true){
		int reminder = sum % B;
		if(sum == 0){
			break;
		}
		sum = sum / B;
		ans.push(reminder);
	}
	
	while(!ans.empty()){
		std::cout << ans.top() << " ";
		ans.pop();
	}
	
}