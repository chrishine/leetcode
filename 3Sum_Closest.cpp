#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &num, int target){
	sort(num.begin(), num.end());
	int ans = num[0] + num[num.size() - 2] + num[num.size() - 1];
	for(int third = num.size() - 1; third >= 2; --third){
		int i = 0, j = third - 1;
		while(i < j){
			int tmp = num[i] + num[j] +num[third];
			if(tmp == target) 
				return tmp;
			else
				if(abs(tmp - target) < abs(ans - target))
					ans = tmp;
			if(target < tmp)
				--j;
			else 
				++i;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {-1,2,1,-4};
	cout << threeSumClosest(input, 1);
	return 0;
}