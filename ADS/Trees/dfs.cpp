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
    void inorderHelper(TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        inorderHelper(node->left, result);
        result.push_back(node->val);
        inorderHelper(node->right, result);
    }

    std::vector<int> inorder(TreeNode* root) {
        std::vector<int> result;
        inorderHelper(root, result);
        return result;
    }

/* In-order Depth-First Search Traversal - Iterative solution using a Stack*/
    
    std::vector<int> inorderTraversal(TreeNode* root) {
      std::vector<int> result;
      std::stack<TreeNode*> myStack;
      TreeNode* currentNode = root;
      
      while (currentNode || !myStack.empty()) {
          // Go as far left as possible
          while (currentNode) {
              myStack.push(currentNode);
              currentNode = currentNode->left;
          };
          
          // Process current node and go right
          currentNode = myStack.top();
          myStack.pop();
          result.push_back(currentNode->val);
          currentNode = currentNode->right;
      }
      
      return result;
    }

/* Post-order Depth-First Search Traversal - Recursive solution*/

    void postorderHelper(TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        postorderHelper(node->left, result);
        postorderHelper(node->right, result);
        result.push_back(node->val);
    }


    std::vector<int> postorder() {
        std::vector<int> result;
        postorderHelper(root, result);
        return result;
    }


/* Post-order Depth-First Search Traversal - Iterative solution using 1 Stack*/
    std::vector<int> postOrderOneStack(TreeNode* root) {
        std::stack<TreeNode*> myStack;
        std::vector<int> result;
        TreeNode* lastVisited = nullptr;

        while(root || !myStack.empty()) {
            if (root) {
                myStack.push(root);
                root = root->left;
            }
            else {
                TreeNode* peekNode = myStack.top();
                if (peekNode->right && lastVisited != peekNode->right) {
                    root = peekNode->right;
                }
                else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    myStack.pop();
                }
            }
        }
        return result;
    }


/* Post-order Depth-First Search Traversal - Iterative solution using 2 Stacks*/
    std::vector<int> postOrderTwoStacks(TreeNode* root) {
        std::stack<TreeNode*> stackOne;
        std::stack<TreeNode*> stackTwo;
        std::vector<int> result;
        if (!root) return result;
        stackOne.push(root);
        TreeNode* currentNode = root;


        while(!stackOne.empty()) {
            currentNode = stackOne.top();
            stackTwo.push(currentNode);
            stackOne.pop();
            if (currentNode->left) {
                stackOne.push(currentNode->left);
            }
            if (currentNode->right) {
                stackOne.push(currentNode->right);
            }
        }

        while(!stackTwo.empty()) {
            result.push_back(stackTwo.top()->val);
            stackTwo.pop();
        }
        return result;
    };

};




int main() {



  return 0;
} 

