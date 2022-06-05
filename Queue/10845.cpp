#include <iostream>
#include <string>

class Queue{
private:
	const int MAX_SIZE = 10000;
	int arr[10000];
	int size;
	int front;
	int back;
	bool empty;
	
	int NextIdx(int idx){
		if(idx + 1 == MAX_SIZE){
			return 0;
		}
		return idx + 1;
	}
public:
	Queue(){
		size = 0;
		front = 0;
		back = 0;
		empty = true;
	}
	void Push(int n){
		if(empty){
			arr[back] = n;
			empty = false;
		}else{
			back = NextIdx(back);
			arr[back] = n;
		}
		
		arr[back] = n;
		size++;
	}
	
	int Pop(){
		 if(empty){
			return -1;
		}
		if(front == back){
			empty = true;
			size--;
			return arr[front];
		}
		int n = arr[front];
		front = NextIdx(front);
		size--;
		return n;
	}
	
	int Size(){
		return size;
	}
	
	bool Empty(){
		return empty;
	}
	
	int Front(){
		if(empty){
			return -1;
		}
		return arr[front];
	}
	
	int Back(){
		if(empty){
			return -1;
		}
		return arr[back];
	}
};

int main(){
	Queue queue = Queue();
	int n, num;
	std::string s;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		if(s == "push"){
			std::cin >> num;
			queue.Push(num);
		}else if(s == "pop"){
			num = queue.Pop();
			std::cout << num << "\n";
		}else if(s == "size"){
			std::cout << queue.Size() << "\n";
		}else if(s == "empty"){
			std::cout << queue.Empty() << "\n";
		}else if(s == "front"){
			std::cout << queue.Front() << "\n";
		}else if(s == "back"){
			std::cout << queue.Back() << "\n";
		}
	}
}