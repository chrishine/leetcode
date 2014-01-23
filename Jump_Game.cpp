#include <iostream>

using namespace std;

bool canJump(int A[], int n){
	int max_end = 1;
	for(int i = 0; i < max_end && max_end < n; ++i){
		max_end = max(max_end, A[i] + i + 1);
	}
	return max_end >= n;
}

int main(int argc, char const *argv[])
{
	int A[] = {2,3,1,1,4};
	cout << canJump(A, sizeof(A) / sizeof(int));
	return 0;
}