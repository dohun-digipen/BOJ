#include<iostream>

int main(){
	int m,d,total = 0;
	std::string day;
	std::string weeks[7] = {"SUN", "MON", "TUE", "WED", "THU", 
							"FRI", "SAT"};
	int months[12] = {31, 28, 31, 30, 
					  31, 30, 31, 31, 30,
					  31, 30, 31};
	std::cin >> m >> d;
	
	for(int i = 0; i < m - 1; i++){
		total = total + months[i];
	}
	m = total + d;
	d = m % 7;
	std::cout << weeks[d] << "\n";
}