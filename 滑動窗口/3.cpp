class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(!len) return 0;
        unordered_set<char> now;
        int mx = 0;
        int le = 0;

        for(int i = 0; i < len; i ++){
            while(now.find(s[i]) != now.end()){
                now.erase(s[le]);
                le ++;
            }
            mx = max(mx, i - le + 1);
            now.insert(s[i]);
        }
        return mx;
    }
};
