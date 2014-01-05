#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n){
	int ai = m - 1;
	int bi = n - 1;
	int sumi = m + n - 1;
	while(ai != -1 && bi != -1){
		if(A[ai] > B[bi]){
			A[sumi] = A[ai];
			--sumi;
			--ai; 
		} else {
			A[sumi] = B[bi];
			--sumi;
			--bi;
		}
	}
	if(ai == -1 && bi != -1){
		for(int i = 0; i <= bi; ++i){
			A[i] = B[i];
		}
	}
}

int main(int argc, char const *argv[])
{
	int A[] = {5,6,7,0,0,0,0};
	int B[] = {1,2,3,4};
	
	merge(A, 3, B, 4);
	for(int i = 0; i < 7; ++i){
		cout << A[i];
	}
	return 0;
}