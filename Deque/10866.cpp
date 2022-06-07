#include <iostream>
#include <string>

class Deque{
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
	
	int BackIdx(int idx){
		if(idx == 0){
			return MAX_SIZE - 1;
		}
		return idx - 1;
	}
public:
	Deque(){
		size = 0;
		front = 0;
		back = 0;
		empty = true;
	}
	
	void PushFront(int n){
		if(empty){
			arr[front] = n;
			empty = false;
		}else{
			front = BackIdx(front);
		}
		
		arr[front] = n;
		size++;
	}
	
	void PushBack(int n){
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
	
	int PopFront(){
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
	
	int PopBack(){
		 if(empty){
			return -1;
		}
		if(front == back){
			empty = true;
			size--;
			return arr[back];
		}
		int n = arr[back];
		back = BackIdx(back);
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
	Deque queue = Deque();
	int n, num;
	std::string s;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		if(s == "push_front"){
			std::cin >> num;
			queue.PushFront(num);
		}else if(s == "push_back"){
			std::cin >> num;
			queue.PushBack(num);
		}else if(s == "pop_front"){
			num = queue.PopFront();
			std::cout << num << "\n";
		}else if(s == "pop_back"){
			num = queue.PopBack();
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