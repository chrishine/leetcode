#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
    auto low = 0;
    auto high = n - 1;
    while(low < high){
    	int mid = low + (high - low) / 2;
    	if(A[mid] < target){
    		low = mid + 1;
    	}
    	if(A[mid] > target){
    		high = mid;
    	}
    	if(A[mid] == target){
    		return mid;
    	}
    }
    if (A[low] < target)
    {
    	return low + 1;
    }
    return low;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,3,5,6};
	cout << searchInsert(A, 4, 5) <<endl;
	cout << searchInsert(A, 4, 2) <<endl;
	cout << searchInsert(A, 4, 7) <<endl;
	cout << searchInsert(A, 4, 0) <<endl;
	cout << searchInsert(A, 4, 4) <<endl;

	return 0;
}