#include <iostream>

using namespace std;

int singleNumber(int A[], int n){
	int bit[32] = {0};
	int result = 0;
	for(int i = 0; i < 32; ++i){
		for(int j = 0; j < n; ++j){
			if((A[j] >> i) & 1)
				++bit[i];
		}
		result |= (bit[i] % 3) << i ;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,1,2,3,1,2,3,4134423};
	cout << singleNumber(A,10);
	return 0;
}