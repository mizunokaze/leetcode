class Solution {
public:
    vector<int> ans;
    int base, cnt, mxCnt;

    void update(int x){
        if(x == base) cnt++;
        else cnt = 1, base = x;
        if(cnt == mxCnt) ans.push_back(base);
        if(cnt > mxCnt) mxCnt = cnt, ans = vector<int> {base};
    }
    void dfs(TreeNode* o){
        if(!o) return;
        dfs(o->left);
        update(o->val);
        dfs(o->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
