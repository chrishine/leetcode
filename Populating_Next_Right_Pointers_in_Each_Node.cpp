#include <iostream>
#include <string>
#include <stack>
#include <functional>
#include <unordered_map>
#include <vector>
#include <ctime>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
        
}