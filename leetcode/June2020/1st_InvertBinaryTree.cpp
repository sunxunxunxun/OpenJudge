/*数据结构
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr){}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
}*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->right);
        invertTree(root->left);
        return root;
        /*学习下大佬的代码
        TreeNode* temp;
        return root ? (temp = invertTree(root->left), root->left = invertTree(root->right), root->right = temp, root) : root;*/
    }
};
