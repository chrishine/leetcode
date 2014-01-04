#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool match(const string &des, const string &src){
	for (int i = 0; i < src.length(); ++i){
		if(!(src[i] == des[i] || src[i] == '?'))
			return false;
	}
	return true;
}

bool isMatch(const char *s, const char *p) {
	string des(s), src(p);
	if( des.empty() || src.empty())
		return false;
	int first = src.find_first_of('*'), last = src.find_last_of('*');
	if(first == -1)
		return des.length() == src.length() && match(des, src);
	if(last == src.size() - 1 && !match(des.substr(0, first), src.substr(0, first)))
			return false;
	if( last < src.size() - 1 && !(match(des.substr(0, first), src.substr(0, first)) && match(des.substr(last), src.substr(last))) )
		return false;
	des = des.substr(first, last - first);
	src = src.substr(first, last - first);
	int desi = 0, srci = 0;
	while(1){
		while(srci < src.length() && src[srci] == '*')
			++srci;
		if(srci == src.length())
			return true;
		int tmp = srci;
		while( src[srci] != '*')
			++srci; 
		auto next = src.substr(tmp, srci);
		while(desi + next.length() < des.length() && !match(next, des.substr(desi, next.length())))
			++desi;
		if(desi + next.length() > des.length())
			return false;
		desi = desi + next.length();
	}
	return true;
}

int main(int argc, char const *argv[])
{
	const char *s = "b";
	const char *p = "?*?*";
	cout << isMatch(s, p) << endl;
	return 0;
}