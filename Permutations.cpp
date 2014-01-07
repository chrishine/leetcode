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

vector<vector<int> > permute(vector<int>& num){
	sort(num.begin(), num.end());
	vector<vector<int> > ans;
	do{
		ans.push_back(num);
	} while (permutation(num.begin(), num.end()));
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> single = {1,3,2,};
	vector<vector<int>> ans = permute(single);
	for(auto tmp : ans){
		for(auto t : tmp)
			cout << " " << t;
		cout << endl;
	}
	return 0;
}