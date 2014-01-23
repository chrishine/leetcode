#include <iostream>

using namespace std;

double gen(double x, int n){
	if(!n) return 1;
	double ans = gen(x,n / 2);
	if(n&1)
		return ans*ans*x;
	else 
		return ans*ans;
}

double pow(double x, int n){
	if(n < 0)
		return 1.0/gen(x, -n);
	else 
		return gen(x, n);
}

int main(int argc, char const *argv[])
{
	cout << pow(3.0, -4);
	return 0;
}