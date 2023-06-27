#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    if (root == NULL)
        return vector<int>();

    if (root->data == x)
    {
        return vector<int>{x};
    }

    vector<int> leftPath = pathInATree(root->left, x);
    if (!leftPath.empty())
    {
        leftPath.insert(leftPath.begin(), root->data);
        return leftPath;
    }

    vector<int> rightPath = pathInATree(root->right, x);
    if (!rightPath.empty())
    {
        rightPath.insert(rightPath.begin(), root->data);
        return rightPath;
    }

    return vector<int>();
}
