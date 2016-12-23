/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) 
{
    return dfs(root, 0);  
}
int dfs(struct TreeNode* node, int isLeft)
{
    if(!node) return 0;

    if(isLeft == 1 && !node->left && !node->right)
        return node->val;

    return dfs(node->left, 1) + dfs(node->right, 0);
}
