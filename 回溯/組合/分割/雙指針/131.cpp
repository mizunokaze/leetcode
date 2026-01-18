class Solution {
private:
    vector<vector<string>> res;
    vector<string> now;
    void backT(const string& s, int ind){
        if(ind >= s.size()){
            res.push_back(now);
            return;
        }
        for(int i = ind; i < s.size(); i ++){
            if(isPalindrome(s, ind, i)){
                string str = s.substr(ind, i - ind + 1);
                now.push_back(str);
            }
            else continue;
            backT(s, i + 1);
            now.pop_back();
        }
    }
    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i < j; i ++, j --){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backT(s, 0);
        return res;
    }
};
