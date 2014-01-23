#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target){
	vector<int> ans = {-1, -1};
	int low = 0, high = n;
	while(low < high){
		int mid = low + ((high - low) >> 1);
		if(A[mid] < target){
			low = mid + 1;
		} else{
			high = mid;
		}
	}
	if(A[low] != target)
		return ans;
	ans[0] = low;

	high = n;
	while(low < high){
		int mid = low + ((high - low) >> 1);
		if(A[mid] > target){
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	ans[1] = high - 1;
	return ans;
}

int main(int argc, char const *argv[])
{
	int B[] = {5, 7, 7, 8, 8, 10};
	for(auto tmp : searchRange(B, sizeof(B) / sizeof(int), 8))
		cout << tmp << " ";
}