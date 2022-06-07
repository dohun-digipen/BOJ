#include <iostream>
#include <string>
#include <algorithm>
int arr[50][50];
int n, m;

long long Sum(int tn, int tm, int bn, int bm){
	long long sum = 0;
	for(int i = tn; i <= bn; i++){
		for(int j = tm; j <= bm; j++){
			sum += arr[i][j];
		}
	}
	return sum;
}

long long CrossMax(){
	long long max = 0;
	long long maxA, maxB, maxC, maxD;
	long long a, b, c, d;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m - 1; j++){
			a = Sum(0, 0, i, j);
			b = Sum(0, j + 1, i, m - 1);
			c = Sum(i + 1, 0, n - 1, j);
			d = Sum(i + 1, j + 1, n - 1,  m - 1);

			//a+b, c, d
			maxA = (a + b) * c * d; 
			//a+c, b, d
			maxB = (a + c) * b * d;
			//a, b+d, c
			maxC = a * (b + d) * c;
			//a, c+d, b
			maxD = a * (c + d) * b;
			
			//std::cout << maxA << " " << maxB << " " << maxC << " " << maxD << " " << "\n";
			maxA = std::max(std::max(maxA, maxB), std::max(maxC, maxD));
			if(max < maxA){
				max = maxA;
			}
		}
	}
	return max;
}

long long RowMax(){
	long long max = 0;
	long long a, b, c;
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			a = Sum(0, 0, i, m - 1);
			b = Sum(i + 1, 0, j, m - 1);
			c = Sum(j + 1, 0, n - 1, m - 1);
			
			if(max < (a * b * c)){
				max = (a * b * c);
			}
		}
	}
	return max;
}

long long ColMax(){
	long long max = 0;
	long long a, b, c;
	for(int i = 0; i < m - 2; i++){
		for(int j = i + 1; j < m - 1; j++){
			a = Sum(0, 0, n - 1, i);
			b = Sum(0, i + 1, n - 1, j);
			c = Sum(0, j + 1, n - 1, m - 1);
			
			if(max < (a * b * c)){
				max = (a * b * c);
			}
		}
	}
	return max;
}

int main(){
	long long max = 0;
	std::string s;
	
	std::cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		std::cin >> s;
		for(int j = 0; j < m; j++){
			arr[i][j] = s[j] - '0';
		}
	}
	
	if(n == 1){
		max = ColMax();
	}else if(m == 1){
		max = RowMax();
	}else{
		long long maxH, maxC, maxP;
		maxP = ColMax();
		maxH = RowMax();
		maxC = CrossMax();
		//std::cout << "Max : " << maxC << " " << maxH << " " << maxP << "\n";
		max = std::max(std::max(maxC, maxH), maxP);
	}

	std::cout << max;
}