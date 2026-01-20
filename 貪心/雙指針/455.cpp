class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);
        int i = 0;
        for(int x : s){
            if(i < g.size() && g[i] <= x) i ++;
        }
        return i;
    }
};
