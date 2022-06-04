#include <iostream>
#include <string>

class Stack{
private:
	int arr[10000];
	int size;
	int isEmpty;
	int lastIdx;
public:
	Stack(){
		size = 0;
		isEmpty = true;
		lastIdx = -1;
	}
	void Push(int num){
		if(isEmpty == true){
			isEmpty = false;
		}
		lastIdx++;
		size++;
		arr[lastIdx] = num;
	}
	
	int Pop(){
		if(Empty() == true){
			return -1;
		}
		
		int n = arr[lastIdx];
		size--;
		lastIdx--;
		if(size == 0){
			isEmpty = true;
		}
		return n;
	}
	
	int Size(){
		return size;
	}
	
	bool Empty(){
		return isEmpty;
	}
	
	int Top(){
		if(Empty() == true){
			return -1;
		}
		
		return arr[lastIdx];
	}
	
	void Info(){
		std::cout << "Size : " << size << "\n" 
			<< "IsEmpty : " << isEmpty << "\n";
		for(int i = 0; i < size; i++){
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
};

int main(){
	Stack stack = Stack();
	std::string s;
	int n, comd;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		if(s == "push"){
			std::cin >> comd;
			stack.Push(comd);
		}else if(s == "pop"){
			std::cout << stack.Pop() << "\n";
		}else if(s == "size"){
			std::cout << stack.Size() << "\n";
		}else if(s == "empty"){
			std::cout << stack.Empty() << "\n";
		}else if(s == "top"){
			std::cout << stack.Top() << "\n";
		}
	}
}