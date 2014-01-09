#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(int A[], int n){
	if(!n) return 0;
	int pointer = A[0];
	int times = -1;
	for(int i = 1; i < n; ++i){
		if(pointer == A[i]){
			++times;
			if(times){
				for(int j = i; j < n - 1; ++j){
					A[j] = A[j + 1];
				}
				--i; --n;
			}
		} else{
			times = -1;
			pointer = A[i];
		}
	}
	return n;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,1,1,2,3};
	cout << removeDuplicates(A, sizeof(A)/sizeof(int));
	for(int i = 0; i < 4; ++i)
		cout << A[i] << " ";
	return 0;
}