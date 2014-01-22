#include <iostream>

using namespace std;

int search(int A[], int n, int target){
	int low = 0, high = n - 1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(A[mid] == target) return mid;
		if(A[low] <= A[mid]){
			if(A[low] <= target && target < A[mid])
				high = mid - 1;
			else 
				low = mid + 1;
		} else {
			if(A[mid] < target && target <= A[high])
				low = mid + 1;
			else 
				high = mid -1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int B[] = {3,1};
	cout << search(B, 2, 1);
	return 0;
}