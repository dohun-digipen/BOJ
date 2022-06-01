#include <iostream>
#include <algorithm>
#include <string>

class Student{
public:
	std::string name;
	int kor;
	int math;
	int eng;
	
	void SetStudent(std::string _name, int _kor, int _eng, int _math){
		name = _name;
		kor = _kor;
		math = _math;
		eng = _eng;
	}
};

bool Compare(const Student& a, const Student& b){
	if(a.kor == b.kor){
		if(a.eng == b.eng){
			if(a.math == b.math){
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, kor, math, eng;
	std::string name;
	Student students[100000];
	
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> name >> kor >> eng >> math;
		students[i] = Student();
		students[i].SetStudent(name, kor, eng, math);
	}
	
	std::sort(students, students + n, Compare);

	for(int i = 0; i < n; i++){
		std::cout << students[i].name << "\n";
	}
}