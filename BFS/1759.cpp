#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int l, c;
char ns[5] = {'a', 'e', 'i', 'o', 'u'};
std::vector<std::string> ans;
std::vector<char> letters;

bool Check(const std::string& word){
	int cnt = 0;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < 5; j++){
			if(word[i] == ns[j]){
				cnt++;
			}
		}
	}
	
	if(cnt > 0 && word.size() - cnt > 1){
		return true;
	}
	return false;
}

void DFS(const std::string& word, int idx, int cnt){
	if(cnt == l){
		if(Check(word) == true){
			ans.push_back(word);
		}
		return;
	}
	
	for(int i = idx; i < c; i++){
		std::string temp = word;
		temp.push_back(letters[i]);
		DFS(temp, i + 1, cnt + 1);
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> l >> c;
	char a;
	for(int i = 0; i < c; i++){
		std::cin >> a;
		letters.push_back(a);
	}
	
	std::sort(letters.begin(), letters.end());
	DFS(std::string(), 0, 0);
	for(auto s : ans){
		std::cout << s << "\n";
	}
}