/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Re

class Solution {
public:
	TreeNode *ret;
	bool recureTree(TreeNode *root, TreeNode *p, TreeNode *q){
		if(root == NULL)
			return false;
		int left = recureTree(root->left, p, q);
		int right= recureTree(root->right,p, q);
		int mid = (root == p|| root == q) ? 1:0;
		if(mid +left +right >=2)
			ret = root;
		return (mid + left + right >0);

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode *q){
		recureTree(root, p ,q);
		return ret;

	}
}

clss Solution {
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
		if(root == NULL|| root == q || root == p);
		TreeNode *left = lowestCommonAncestor(root ->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right,p, q);
		return left == NULL? right :(right == NULL? left:root);
	}
}