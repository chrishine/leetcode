#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int getSeg(unordered_set<int>& table, int num, bool des){
	int seg = 0;
	if(des){
		while(table.count(++num)){
			++seg;
			table.erase(num);
		}
	} else {
		while(table.count(--num)){
			++seg;
			table.erase(num);
		}
	}
	return seg;
}

int longestConsecutive(vector<int> &num){
	if(num.empty()) return 0;
	unordered_set<int> table;
	for(auto tmp : num)
		table.insert(tmp);
	int length = 0;
	for(auto tmp : num){
		if(table.count(tmp)){
			int seg = getSeg(table, tmp, true) + getSeg(table, tmp, false) + 1;
			if(seg > length)
				length = seg;
		}
	}
	return length;
} 

int main(int argc, char const *argv[])
{
	vector<int> input = {100, 4, 200, 1, 3, 2};
	cout << longestConsecutive(input);
	return 0;
}