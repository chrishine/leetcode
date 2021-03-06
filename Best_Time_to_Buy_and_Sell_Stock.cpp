#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	if(prices.size() <= 1)
		return 0;
    int profit = 0, low = prices[0], high = prices[1]; 
    for (int i = 1; i < prices.size(); ++i){
        	if(low <= prices[i])
        		profit = max(profit, prices[i] - low);
        	if(low > prices[i])
        		low = prices[i]; 
    }    
    return profit;
}

int main(int argc, char const *argv[])
{
	vector<int> stock = {3,2,6,5,0,3};
	cout << maxProfit(stock);
	return 0;
}