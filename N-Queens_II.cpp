#include <iostream>

using namespace std;

void gen(int row, int ld, int rd, int& ans, int max_end){
	int pos, p;
	if(row != max_end){
		pos = max_end &(~(row | ld | rd));
		while(pos != 0){
			p = pos &(-pos);
			pos = pos - p;
			gen(row + p, (ld + p) << 1, (rd + p) >> 1, ans, max_end);
		}
	} else{
		++ans;
	}
}

int totalNQueens(int n){
	int ans = 0;
	int max_end = (1 << n) - 1;
	gen(0, 0, 0, ans, max_end);
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << totalNQueens(4);
	return 0;
}