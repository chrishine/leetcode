#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b){
	string ans;
	int flag = 0;
	int sum = 0;
	int i = a.size() - 1, j = b.size() - 1;
	int aa = 0, bb = 0;
	while(i >= 0 || j >= 0 || flag){
		aa = (i >= 0 ? a[i] - '0' : 0);
		bb = (j >= 0 ? b[j] - '0' : 0);
		sum = aa + bb + flag;
		flag = sum / 2;
		sum &= 1;
		ans.insert(0, 1, sum + '0');
		i >= 0? --i : i;
		j >= 0? --j : j;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string a("11"), b("1");
	cout << addBinary(a, b);
	return 0;
}