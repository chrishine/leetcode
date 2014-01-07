#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

template<typename It>
bool permutation(It begin, It end)
{
	if(begin == end) return false;
	It i = end;
	if(--i == begin) return false;
    
    while(true){
    	It j = i;
    	--i;
    	if( *i < *j){
    		It k = end;
    		while(!(*i < *--k))
    			;
    		iter_swap(i,k);
    		reverse(j,end);
    		return true;
    	}
    	if(i == begin){
    		reverse(begin,end);
    		return false;
    	}
    }
}

string getPermutation(int n, int k){
	vector<int> prev;
	int seg = 1;
	for(int i = 2; i < n; ++i){
		seg *= i; 
	}
	int left = (k - 1) / seg;
	int other = (k - 1) % seg;

	prev.push_back(left + 1);
	for(int i = 1; i <= n; ++i){
		if(left + 1 != i)
			prev.push_back(i);
	}

	while(other--){
		permutation(prev.begin(), prev.end());
	}
	string  result = "" ;
	for(auto tmp : prev){
		result += to_string(tmp);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	auto c = clock();
	cout << getPermutation(1, 1) << endl;
	cout << clock() - c << endl;
	return 0;
}