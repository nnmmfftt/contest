




			return NULL;
			return NULL;
		if(root == NULL)
		if(root == NULL)
		invertTree(root->left);
		invertTree(root->left);
		return root;
		root->left =  invertTree(rightTree);
		root->right = invertTree(root->left);
		root.left =  invertTree(rightTree);
		root.right = invertTree(root->left);
		TreeNode *rightTree = root.right;
		TreeNode rightTree = root->right;
	TreeNode* invertTree(TreeNode *H){
	TreeNode* invertTree(TreeNode *H){
	}
	}
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * Definition for a binary tree node.
 * struct TreeNode {
 * Using any traverse method
 * };
 */
 */
/*
/**
class Solution {
class Solution {
public:
public:
}
}