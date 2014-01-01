#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
	if(n == 0)
		return 0;
	auto tmp = A[0];
	for(int i = 1;i < n; ++i){
		if(tmp < A[i]){
			tmp = A[i];
		}else if(tmp == A[i]){
			for(auto j = i;j < n; ++j){
				A[j - 1] = A[j];
			}
			--i;
			--n;
		}
	}
	return n;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,1,1,2,2,2};
	auto tmp = removeDuplicates(A,6);
	cout << tmp << endl;
	for(auto i = 0; i < tmp; ++i){
		cout << " " << A[i];
	}
	return 0;
}