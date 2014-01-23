#include <iostream>

using namespace std;

int trap(int A[], int n){
	int low = 0, high = n - 1;
	int ans = 0;
	int k = 0;
	while(low < high){
		if(A[low] <= A[high]){
			k = low + 1;
			while(A[low] > A[k]){
				ans += A[low] - A[k++];
			}
			low = k;
		} else {
			k = high - 1;
			while(A[k] < A[high]){
				ans += A[high] - A[k--]; 
			}
			high = k;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int B[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trap(B, sizeof(B) / sizeof(int));
	return 0;
}