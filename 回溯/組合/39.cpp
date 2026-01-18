class Solution {
private:
    vector<vector<int>> res;
    vector<int> now;
    void getComb(vector<int>& cand, int target, int sum, int ind){
        if(sum > target) return;
        if(sum == target) {
            res.push_back(now);
            return;
        }
        for(int i = ind; i < cand.size(); i ++){
            sum += cand[i];
            now.push_back(cand[i]);
            getComb(cand, target, sum, i);
            sum -= cand[i];
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        getComb(candidates, target, 0, 0);
        return res;
    }
};
