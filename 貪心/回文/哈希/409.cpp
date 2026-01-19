class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for(char c : s) cnt[c] ++;

        int res = 0;
        for(auto c : cnt){
            int v = c.second;
            res += v / 2 * 2;
            if(v % 2 && !(res % 2)) res ++;
        }
        return res;
    }
};
