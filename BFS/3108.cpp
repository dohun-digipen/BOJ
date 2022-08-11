#include <iostream>
#include <vector>

bool isFoundZero = false;

struct Box{
	int x1;
	int y1;
	int x2;
	int y2;
};

std::vector<std::vector<Box>> sets;

void MergeSet(const std::vector<int> cnt){
	std::vector<Box> nSet;
	for(auto n : cnt){
		for(auto box : sets[n]){
			nSet.push_back(box);
		}
		sets[n].clear();
	}
	sets.push_back(nSet);
}

void MakeSet(const Box& box){
	std::vector<int> setCnt;
	for(int i = 0 ; i < sets.size(); i++){
		for(int j = 0; j < sets[i].size(); j++){
			if (box.y2 > sets[i][j].y2 && sets[i][j].x2 < box.x2 && sets[i][j].y1 > box.y1 && box.x1 < sets[i][j].x1){
				continue;
			}else if (sets[i][j].y2 > box.y2 && box.x2 < sets[i][j].x2 && box.y1 > sets[i][j].y1 && box.x1 > sets[i][j].x1){
				continue;
			}else if (box.y1 > sets[i][j].y2 || box.x1 > sets[i][j].x2 || sets[i][j].y1 > box.y2 || box.x2 < sets[i][j].x1){
				continue;
			}else{
				setCnt.push_back(i);
				break;
			}
		}
	}
	int cnt = setCnt.size();
	if(cnt == 0){
		std::vector<Box> temp;
		temp.push_back(box);
		sets.push_back(temp);
	}else if(cnt == 1){
		sets[setCnt[0]].push_back(box);
	}else{
		MergeSet(setCnt);
	}
}

int main(){
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	Box box{ 0, 0, 0, 0};
	std::vector<Box> temp;
	temp.push_back(box);
	sets.push_back(temp);
	int n;
	int ans = 0;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> box.x1 >> box.y1 >> box.x2 >> box.y2;
		MakeSet(box);
	}
	
	for(auto set : sets){
		if(set.size() > 0){
			ans++;
		}
	}
	
	if(sets[0].size() > 1){
		ans--;
	}
	std::cout << ans;
}