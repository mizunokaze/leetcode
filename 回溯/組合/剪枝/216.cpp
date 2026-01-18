class Solution {
private:
    vector<vector<int>> res;
    vector<int> now;
    void getComb(int k, int n, int ind, int sum, vector<bool>& used){
        if(sum > n) return;
        if(now.size() == k && sum == n) {
            res.push_back(now);
            return;
        }
        for(int i = ind; i <= 9 - (k - now.size()) + 1; i ++){
            if(used[i]) continue;
            sum += i;
            used[i] = true;
            now.push_back(i);
            getComb(k, n, i + 1, sum, used);
            sum -= i;
            used[i] = false;
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> used(n, false);
        getComb(k, n, 1, 0, used);
        return res;
    }
};
