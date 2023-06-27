/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <sstream>
#include <queue>
#include <iostream>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if (root == nullptr) {
        return "";
    }

    string serialized;
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        if (node != nullptr) {
            serialized += to_string(node->data) + " ";

            q.push(node->left);
            q.push(node->right);
        } else {
            serialized += "# ";
        }
    }

    return serialized;

}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if (serialized.empty()) {
        return nullptr;
    }

    std::istringstream iss(serialized);
    std::string val;

    iss >> val;

    if (val == "#") {
        return nullptr;
    }

    TreeNode<int>* root = new TreeNode<int>(stoi(val));
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        iss >> val;

        if (val != "#") {
            node->left = new TreeNode<int>(stoi(val));
            q.push(node->left);
        }

        iss >> val;

        if (val != "#") {
            node->right = new TreeNode<int>(stoi(val));
            q.push(node->right);
        }
    }

    return root;

}

