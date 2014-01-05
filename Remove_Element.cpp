#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
    for(int i = 0; i < n; ++i){
    	if(A[i] == elem){
    		for(int j = i; j < n - 1; ++j){
    			A[j] = A[j + 1];
    		}
    		--i; --n;
    	}
    }    
    return n;
}

int main(int argc, char const *argv[])
{
	int A[] = {2, 2, 3};
	cout << removeElement(A, sizeof(A) / sizeof(int), 2);
	return 0;
}