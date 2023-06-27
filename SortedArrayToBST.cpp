#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* constructBST(vector<int>& arr, int start, int end) {
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    root->left = constructBST(arr, start, mid - 1);
    root->right = constructBST(arr, mid + 1, end);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int>& arr, int n) {
    return constructBST(arr, 0, n - 1);
}
