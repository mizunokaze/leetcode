class Solution {
private:
    vector<string> res;
    void backT(string& s, int ind, int dot){
        if(dot == 3){
            if(isValid(s, ind, s.size() - 1)) res.push_back(s);
            return;
        }

        for(int i = ind; i < s.size(); i ++){
            if(isValid(s, ind, i)){
                s.insert(s.begin() + i + 1, '.');
                dot ++;
                backT(s, i + 2, dot);
                dot --;
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }
    
    bool isValid(const string& s, int start, int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;

        int num = 0;
        for(int i = start; i <= end; i ++){
            if(s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return res;
        backT(s, 0, 0);
        return res;
    }
};
