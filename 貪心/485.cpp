class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = -1, sum = 0;
        for(auto i : nums){
            if(i){
                if(sum >= 1) sum ++;
                else sum = 1;
            }
            else sum = 0;
            ans = max(ans, sum);
        }
        return ans;
    }
};
