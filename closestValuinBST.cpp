/*

This is to find closest value from BST
Input: BST and target
OUT: Need to find node val which is closest to the target

*/

//This can be done in novel method like traversal and note down min diff so far and return that val at the end
// rumtime would be O(N), we can improve runtime since we know that given TRee is BST
// Second approach is use BST property to get down the runtime for average case

// First approach, brute force , traver entire tree

void traverse(TreeNode *root, int target, int &Min, int &val)
{
	if (!root) return;
	
	if (abs(root->val - target) < Min)
	{
		Min = abs(root->val - target);
		val = root->val;
	}
	
	// Do the same for left and right sub trees
	
	traverse(root->left, target, Min, val);
	traverse(root->right, target, Min, val);
}


//Second approach, using BST property

int closestVal(TreeNode *root, int target)
{
	if (!root) return 0;
	
	// Left sub tree choice
	if (root->val > target && root->left)
	{
		int l = closestVal(root->left, target);
		
		if ( abs(l - target) < abs(root->val - target) )
			return l;
			
		return root->val;
	}
	
	// Right sub tree choice
	if (root->val < target && root->right)
	{
		int r = closestVal(root->right, target);
		
		if ( abs(r - target) < abs(root->val - target) )
			return r;
			
		return root->val;
	}
	
	// If matches with root->val
	return root->val;


}
	

// NOTE:  Code is not ompiled and tested.
