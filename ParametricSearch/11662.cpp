#include <iostream>
#include <cmath>
#include <algorithm>

struct Point{
	double x;
	double y;
};

Point start1, start2, dest1, dest2;

double f(Point n1, Point n2){
	double dist;
	dist = std::sqrt(std::pow((n2.x - n1.x), 2) + std::pow((n2.y - n1.y), 2));
	return dist;
}

int main(){
	std::cin >> start1.x >> start1.y >> dest1.x >> dest1.y
		>> start2.x >> start2.y >> dest2.x >> dest2.y;
	int t = 100;
	double mid1, mid2;
	
	while(t--){
		mid1 = f(start1, start2);
		mid2 = f(dest1, dest2);
		if(mid1 > mid2){
			start1 = Point{start1.x + (dest1.x - start1.x) / 3, start1.y + (dest1.y - start1.y) / 3};
			start2 = Point{start2.x + (dest2.x - start2.x) / 3, start2.y + (dest2.y - start2.y) / 3};
		}else if(mid1 < mid2){
			dest1 = Point{dest1.x - (dest1.x - start1.x) / 3, dest1.y - (dest1.y - start1.y) / 3};
			dest2 = Point{dest2.x - (dest2.x - start2.x) / 3, dest2.y - (dest2.y - start2.y) / 3};
		}else{
			break;
		}
	}
	
	std::cout << std::fixed;
	std::cout.precision(10);
	std::cout << std::min(mid1, mid2);
}