// pre
class Solution {
public:
    bool isValidBST(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
        if(root == nullptr) return true;
        long long x = root->val;
        return left < x && x < right && 
        isValidBST(root->left, left, x) &&
        isValidBST(root->right, x, right);
    }
};
// inorder
class Solution {
    long long pre = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(!isValidBST(root->left)) return false;
        if(root->val <= pre) return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};
// post
class Solution {
    pair<long long, long long> dfs(TreeNode* node){
        if(node == nullptr) {
            return {LLONG_MAX, LLONG_MIN};
        }
        auto[l_min, l_max] = dfs(node->left);
        auto[r_min, r_max] = dfs(node->right);
        long long x = node->val;
        if(x <= l_max || x >= r_min) return {LLONG_MIN, LLONG_MAX};
        return {min(l_min, x), max(r_max, x)};
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root).second != LLONG_MAX;
    }
};
