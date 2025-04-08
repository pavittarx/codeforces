// Tress & Binary Search Trees (BST)
#include <iostream>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }

  ~TreeNode() {}
};

void insert(TreeNode*& node, int val) {
  if (node == nullptr) {
    TreeNode* temp = new TreeNode(val);
    node = temp;
    return;
  }

  if (val == node->val) {
    cout << "[insert]: Value is already present, duplicates are not allowed."
         << endl;
    return;
  }

  if (val < node->val) {
    insert(node->left, val);
  } else if (val > node->val) {
    insert(node->right, val);
  }
}

TreeNode* search(TreeNode*& node, int key) {
  if (node == nullptr) {
    cout << "[search] Not Found" << endl;
    return nullptr;
  }

  if (key == node->val) {
    cout << "[search] Key " << key << " Found" << endl;
    return node;
  }

  if (key < node->val) {
    return search(node->left, key);
  }

  if (key > node->val) {
    return search(node->right, key);
  }

  return nullptr;
}

void deleteNode(TreeNode*& node, int key) {
  if (node == nullptr) {
    cout << "Not Found, nothing to delete" << endl;
  }

  if (node->val == key) {
    cout << "[delete] Node Found: " << key << endl;

    // Case I: Leaf Node
    if (node->left == nullptr && node->right == nullptr) {
      cout << "[delete] No child: " << node->val << endl;
      node = nullptr;
      return;
    }

    // Case II: One Child Exists (right)
    if (node->left == nullptr && node->right) {
      node = node->right;
      cout << "[delete] One child (right): " << node->val << endl;
      return;
    }

    // Case II: One Child Exists (left)
    if (node->right == nullptr && node->left) {
      node = node->left;
      cout << "[delete] One child (left): " << node->val << endl;
      return;
    }

    // Case IV: Both Child Exists
    if (node->left && node->right) {
      // smallest value in right subtree
      TreeNode* temp = node->right;

      // navigate to extreme right.
      while (temp->left != nullptr) {
        temp = temp->left;
      }

      node->val = temp->val;
      if (temp->right != nullptr) {
        temp = temp->right;
      }

      cout << "[delete] Node Deleted: " << key << endl;
      return;
    }
  }

  if (key < node->val) {
    deleteNode(node->left, key);
  }

  if (key > node->val) {
    deleteNode(node->right, key);
  }
}

void destroyTree(TreeNode* node) {
  if (node == nullptr) {
    return;
  }

  destroyTree(node->left);
  destroyTree(node->right);

  delete node;
  node = nullptr;
}

int main() {
  TreeNode* root = new TreeNode(15);
  cout << "Binary Search Tree" << endl;

  insert(root, 10);
  insert(root, 5);
  insert(root, 7);
  insert(root, 12);
  insert(root, 20);
  insert(root, 27);
  // insert(root, 27);

  search(root, 20);
  search(root, 9);

  deleteNode(root, 27);
  deleteNode(root, 5);
  deleteNode(root, 10);

  destroyTree(root);

  return 0;
}