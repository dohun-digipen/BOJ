#include <iostream>

int main(){
	int a, b, c, temp;
	std::cin >> a >> b;
	
	c = a * b;
	
	//유클리드 호제법을 이용 (최대 공약수)
	//2개의 자연수(또는 정식) a, b에 대해서 a를 b로 나눈 나머지를 r이라 하면(단, a>b), 
	//a와 b의 최대공약수는 b와 r의 최대공약수와 같다. 이 성질에 따라, b를 r로 나눈 나머지 r'를 구하고, 
	//다시 r을 r'로 나눈 나머지를 구하는 과정을 반복하여 나머지가 0이 되었을 때 나누는 수가 a와 b의 최대공약수이다.
	
	while(true){
		if((a % b) == 0){
			std::cout << b << "\n";
			break;
		}
		temp = a % b;
		a = b;
		b = temp;
	}
	
	//최대 공구수 = 두 자연수 곱 / 최대 공약수
	std::cout << c / b << "\n";
}