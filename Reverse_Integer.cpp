#include <iostream>
#include <vector>

using namespace std;

int reverse(int x){
	int r = 0;
	do{
		r = r * 10 + x % 10;
		x = x / 10;
	}while(x);
	return r;
}

int main(int argc, char const *argv[])
{
	int x = -12345;
	cout << reverse(x) << endl;
	return 0;
}