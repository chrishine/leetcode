#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int index;
	for(index = digits.size() - 1; index >= 0; --index){
		if(digits[index] != 9){
			++digits[index];
			return digits;
		} else {
			digits[index] = 0;
		}
	}
	if(index < 0) digits.insert(digits.begin(), 1);
	return digits;
}

int main(int argc, char const *argv[])
{
	vector<int> input;
	plusOne(input);
	for(auto tmp : input)
		cout << tmp << " ";
	return 0;
}