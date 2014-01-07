#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
	vector<vector<int> > ans;
	if(num.size() < 3) return ans;
	sort(num.begin(), num.end());
	vector<int> single(3,0);
	for(int i = num.size() - 1; i >= 2; --i){
		if(i < num.size() - 1 && num[i] == num[i + 1])
			continue;
		if(num[i] < 0)
			break;
		auto target  = -num[i];
		for(int k = 0, j = i - 1; k < j;){
			if(k > 0 && num[k] == num[k - 1]){
				++k;
				continue;
			}
			if(j < i - 1 && num[j] == num[j + 1]){
				--j;
				continue;
			}	
			if(num[k] + num[j] < target){
				++k;
				continue;
			}
			if(num[k] + num[j] > target){
				--j;
				continue;
			}
			if(num[k] + num[j] == target){
				single[0] = num[k];
				single[1] = num[j];
				single[2] = num[i];
				ans.push_back(single);
				++k;--j;
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> input = {0,0,0,0};
	auto c = clock();
	vector<vector<int> > ans = threeSum(input);
	cout <<clock() - c << endl;
	for(auto tmp : ans){
		for(auto t : tmp)
			cout << " " << t;
		cout << endl;
	}
	return 0;
}