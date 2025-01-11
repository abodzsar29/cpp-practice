#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

/* Pre-order Depth-First Search Traversal - Recursive solution*/
    void preorderHelper(TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        result.push_back(node->val);
        preorderHelper(node->left, result);
        preorderHelper(node->right, result);
    }

    std::vector<int> preorder() {
        std::vector<int> result;
        preorderHelper(root, result);
        return result;
    };

/* Pre-order Depth-First Search Traversal - Iterative solution using a Stack*/
    std::vector<int> preOrderIterative(TreeNode* root) {
      std::vector<int> result = {};
      if (!root) return result;
      std::stack<TreeNode*> myStack;
      myStack.push(root);
      while(!myStack.empty()) {
          TreeNode* node = myStack.top();
          result.push_back(node->val);
          myStack.pop();
          if (node->right) {
              myStack.push(node->right);
          }
          if (node->left) {
              myStack.push(node->left);
          }
      }
      return result;
}

/* In-order Depth-First Search Traversal - Recursive solution*/
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorderHelper(node->left, result);
        result.push_back(node->val);
        inorderHelper(node->right, result);
    }

    vector<int> inorder() {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }



};




int main() {



  return 0;
} 

