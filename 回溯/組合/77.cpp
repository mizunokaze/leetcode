class Solution {
private:
    vector<vector<int>> res;
    vector<int> now;
    void getComb(int n, int k, int start){
        if(now.size() == k) {
            res.push_back(now);
            return;
        }
        for(int i = start; i <= n; i ++){
            now.push_back(i);
            getComb(n, k, i + 1);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        getComb(n, k, 1);
        return res;
    }
};
