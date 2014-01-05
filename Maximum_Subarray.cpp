#include <iostream>

using namespace std;

int max_sub_array_pre(int A[], int low, int high){
	if(low == high)
		return A[low];
	int mid = low + (high - low) / 2;
	int left_ans = max_sub_array_pre(A, low, mid);
	int right_ans = max_sub_array_pre(A, mid + 1, high);

	int tmp = 0, left_max = A[mid], right_max = A[mid + 1];
	for(int i = mid; i >= low; --i){
		tmp += A[i];
		left_max = max(tmp, left_max);
	}

	tmp = 0;
	for(int i = mid + 1; i <= high; ++i){
		tmp += A[i];
		right_max = max(tmp, right_max);
	}

	return max(max(left_ans, right_ans), left_max + right_max);
}

int maxSubArray(int A[], int n){
	return max_sub_array_pre(A, 0, n - 1);
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,-1,-2,2,1,-2,1};
	cout << maxSubArray(A, sizeof(A) / sizeof(int));
	return 0;
}