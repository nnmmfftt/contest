class Solution {
public:
	TreeNode* reverseList(TreeNode *H){
		if(root == NULL)
			return NULL;
		TreeNode rightTree = root->right;
		root->right = invertTree(root->left);
		root->left =  invertTree(rightTree);
		return root;
	}
}