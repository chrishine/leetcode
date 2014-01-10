#include <iostream>
#include <vector>

using namespace std;

void sortColors(int A[], int n){
	if(n > 0) {
		vector<int> red;
	vector<int> white;
	vector<int> blue;
	for(int i = 0; i < n; ++i){
		if(A[i] == 0)
			red.push_back(A[i]);
		if(A[i] == 1)
			white.push_back(A[i]);
		if(A[i] == 2)
			blue.push_back(A[i]);
	}
	for(int i = 0; i < red.size(); ++i)
		A[i] = red[i];
	for(int i = red.size(); i < red.size() + white.size(); ++i)
		A[i] = white[i - red.size()];
	for(int i = red.size() + white.size(); i < red.size() + white.size() + blue.size(); ++i)
		A[i] = blue[i - red.size() - white.size()];
	}
}

int main(int argc, char const *argv[])
{
	int A[] = {1,1,1,2,2,0,0};
	sortColors(A, sizeof(A)/sizeof(int));
	for(int i = 0; i < sizeof(A)/sizeof(int); ++i)
		cout << A[i];
	return 0;
}