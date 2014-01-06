#include <iostream>

using namespace std;

string intToRoman(int num){
	string result = "";
	int base[] = {1000,500,100,50,10,5,1};
	char base_c[] = {'M','D','C','L','X','V','I'};
	int index = 0;
	while(num){
		if(index % 2 == 0 && num/base[index] == 4){
			result += base_c[index];
			result += base_c[index - 1];
			num -= base[index] * 4;
		} else if(num >= base[index]){
			result += base_c[index];
			num -= base[index];
		} else if(index % 2 == 0 && num/base[index + 2] == 9){
			result += base_c[index + 2];
			result += base_c[index];
			num -= base[index + 2] * 9;
		} else {
			++index;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	cout << intToRoman(1);
	return 0;
}