class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        string res;
        for(int i = 0; i < nums.size(); i ++) str.push_back(to_string(nums[i]));
        sort(str.begin(), str.end(), 
            [](string& x, string& y){ return y + x < x + y;});
        if(str[0] == "0") return "0";
        for(int i = 0; i < str.size(); i ++) res.append(str[i]);
        return res;
    }
};
