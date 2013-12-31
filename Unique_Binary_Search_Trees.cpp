#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n) {
    vector<int> bst(n + 1, 0);
    bst[0] = bst[1] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=i-1; j++) {
            bst[i] += bst[j]*bst[i-1-j];
        }
    }
    return bst[n];  
}

int main(int argc, char const *argv[])
{
	cout << numTrees(10) << endl;
	return 0;
}