#include <iostream>
#include <cmath>

using namespace std;

int sqrt(int x){
	double tmp = 1.0, ans = 0.0;
	while(true){
		ans = tmp - (tmp*tmp - (double)x) / (2*tmp);
		if(abs(ans - tmp) < 0.000001)
			return (int)ans;
		else
			tmp = ans;
	}
}

int main(int argc, char const *argv[])
{
	cout << sqrt(15);
	return 0;
}