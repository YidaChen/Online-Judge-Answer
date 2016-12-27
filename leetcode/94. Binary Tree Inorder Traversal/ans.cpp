/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <stack>
class Solution {
public:
    std::vector<int> result;
    std::stack<TreeNode*> s;
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        while(root || s.size())
        {
            if(root)
            {
                s.push(root);
                root = root->left;
            }
            else if(s.size())
            {
                root = s.top();
                s.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
