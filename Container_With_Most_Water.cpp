#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height){
	int low = 0, high = height.size() - 1;
	int max_Area = 0;
	while(low < high){
		max_Area = max(max_Area, (high - low) * min(height[high], height[low]));
		if(height[low] < height[high]){
			++low;
		} else {
			--high;
		}
	}
	return max_Area;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {1,2,3,4,5};
	cout << maxArea(input);
	return 0;
}