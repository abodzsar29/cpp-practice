#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {};
};

class BinaryTree {
private:
    TreeNode* root;

    void deleteNodes(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {};
    ~BinaryTree() {
        deleteNodes(root);
    };

    TreeNode* getRoot() { return root;};

};


int main() {



  return 0;
} 
