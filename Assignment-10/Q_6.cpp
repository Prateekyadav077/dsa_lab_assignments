#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

bool checkDuplicates(TreeNode* root, unordered_set<int>& seen) {
    if (!root) return false;

    if (seen.find(root->data) != seen.end())
        return true;

    seen.insert(root->data);

    return checkDuplicates(root->left, seen) ||
           checkDuplicates(root->right, seen);
}

bool hasDuplicate(TreeNode* root) {
    unordered_set<int> seen;
    return checkDuplicates(root, seen);
}

int main() {
    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(3); 

    cout << (hasDuplicate(root) ? "Duplicate Found" : "No Duplicates") << endl;
    return 0;
}
