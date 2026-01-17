class Solution {
private:
        const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
public:
    vector<string> res;
    void getComb(const string& digits, int ind, const string& s) {
        if(ind == digits.size()){
            res.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i ++) getComb(digits, ind + 1, s + letters[i]);
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.size() == 0) return res;
        getComb(digits, 0, "");
        return res;
    }
};
