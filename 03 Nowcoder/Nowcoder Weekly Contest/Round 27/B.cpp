/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tree TreeNode类 
     * @return int整型
     */
    long long f(TreeNode *t)
    {
        if(!t) return 0;
        long long l=f(t->left);
        long long r=f(t->right);
        return 2*max(l,r)+1;
    }
    int getTreeSum(TreeNode* tree) 
    {
        return f(tree)%1000000007;
    }
};
