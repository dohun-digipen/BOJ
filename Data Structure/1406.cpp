#include <iostream>
#include <string>
#include <list>

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::list<char> editor;
	std::string s;
	int n, len;
	std::list<char>::iterator cusor = editor.end();
	char c;
	std::cin >> s;
	len = s.length();
	for(int i = 0; i < len; i++){
		editor.push_back(s[i]);
	}
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> c;
		if(c == 'L'){
			if(cusor != editor.begin()){
				cusor--;
			}
		}else if(c == 'D'){
			if(cusor != editor.end()){
				cusor++;
			}
		}else if(c == 'B'){
			if(cusor != editor.begin()){
				cusor--;
				cusor = editor.erase(cusor);
			}
		}else if(c == 'P'){
			std::cin >> c;
			cusor = editor.insert(cusor, c);
			cusor++;
		}
	}
	for(auto i : editor){
		std::cout << i;
	}
}
