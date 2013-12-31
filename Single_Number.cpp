class Solution {
public:
    int singleNumber(int A[], int n) {
        int tmp = 0;
        for(int i = 0;i != n; ++i){
            tmp ^= A[i];
        }
        return tmp;
    }
};