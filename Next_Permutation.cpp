#include <iostream>
#include <algorithm>
#include <vector>

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

void nextPermutation(vector<int> &num){
	if( !(permutation(num.begin(), num.end())))
		sort(num.begin(), num.end());
}

int main(int argc, char const *argv[])
{
	vector<int> input = {3,2,1};
	nextPermutation(input);
	for(auto tmp : input){
		cout << " " << tmp;
	}
	return 0;
}