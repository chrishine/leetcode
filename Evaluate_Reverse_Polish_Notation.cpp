#include <iostream>
#include <string>
#include <stack>
#include <functional>
#include <unordered_map>
#include <vector>
#include <ctime>

using namespace std;

void build(unordered_map<string,function<int(int, int)>>& binops){
	binops["+"] = [](int i, int j){ return i + j; };


	binops["-"] = [](int i, int j){ return i - j; };


	binops["/"] = [](int i, int j){ return i / j; };


	binops["*"] = [](int i, int j){ return i * j; };

}

int evalRPN(vector<string> &tokens) {
	if(tokens.empty()){
		return 0;
	} 
	unordered_map<string,function<int(int, int)>> binops;
	build(binops);
	stack<int> number;       
	for(auto tmp : tokens){
		if(binops.count(tmp)){
			auto first = number.top();number.pop();
			auto second = number.top();number.pop();
			number.push(binops[tmp](second, first));
		} else {
			number.push(stoi(tmp));
		}
	}
	return number.top();
}

int main(int argc, char const *argv[])
{
	vector<string> t = {"2", "1", "+", "3", "*"};
	vector<string> v = {"4", "13", "5", "/", "+"};
	auto c = clock();
	cout << evalRPN(t) << endl;
	cout << evalRPN(v) << endl;
	cout << clock() - c << endl;
	return 0;
}
