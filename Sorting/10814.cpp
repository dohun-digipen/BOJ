#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Member{
public:
	int age;
	int order;
	std::string name;
	
	Member(int _age, std::string _name, int _order){
		age = _age;
		name = _name;
		order = _order;
	}
};

bool CompareAge(const Member& a, const Member& b){
	if(a.age == b.age){
		return a.order < b.order;
	}
	return a.age < b.age;
}

int main(){
	std::vector<Member> members;
	int n, age;
	std::string name;
	
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> age >> name;
		members.push_back(Member(age, name, i));
	}
	
	std::sort(members.begin(), members.end(), CompareAge);
	
	for(int i = 0; i < n; i++){
		std::cout << members[i].age << " " << members[i].name << "\n";
	}
}