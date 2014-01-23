#include <iostream>

using namespace std;

int jump(int A[], int n){
	int ans = 0;
	int prev = 0;
	int current = 0;
	for(int i = 0; i < n; ++i){
		if(i > prev){
			prev = current;
			++ans;
		}
		current = max(current, i + A[i]);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int A[] = {2,3,1,1,4};
	cout << jump(A, sizeof(A) / sizeof(int));
	return 0;
}