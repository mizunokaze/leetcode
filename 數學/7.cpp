class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        int r = 0, turn = -1;
        string ans;
        vector<string> row(numRows);

        for(auto c : s){
            row[r].push_back(c);
            if(r == 0 || r == numRows - 1) turn = -turn;
            r += turn;
        }
        for(auto a : row)
            ans += a;
        return ans;
    }
};
