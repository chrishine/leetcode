#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> tmp;
	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = i + 1 ; j < numbers.size(); ++j)
		{
			if(numbers[i] + numbers[j] == target){
				tmp.push_back(i + 1);
				tmp.push_back(j + 1);
				break;
			}
		}
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	vector<int> vec = {1, 4, 3, -1};
	for(auto tmp : twoSum(vec, 0)){
		cout << tmp << endl;
	}
	return 0;
}