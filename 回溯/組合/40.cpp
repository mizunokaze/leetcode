class Solution {
private:
    vector<vector<int>> res;
    vector<int> now;
    void getComb(vector<int>& cand, int target, int sum, int ind, vector<bool>& used){
        if(sum == target){
            res.push_back(now);
            return;
        }
        for(int i = ind; i < cand.size() && sum + cand[i] <= target; i ++){
            if(i > 0 && cand[i] == cand[i - 1] && used[i - 1] == false) continue;
            sum += cand[i];
            now.push_back(cand[i]);
            used[i] = true;
            getComb(cand, target, sum, i + 1, used);
            used[i] = false;
            sum -= cand[i];
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        getComb(candidates, target, 0, 0, used);
        return res;
    }
};
