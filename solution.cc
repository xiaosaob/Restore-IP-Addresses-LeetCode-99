// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s,0,4,"",res);
        return res;
    }
    
    void helper(string s, int startIdx, int num, string sol, vector<string> &res) {
        if(s.size()-startIdx < num || s.size()-startIdx > 3*num)
            return;
        if(num == 0) {
            sol.pop_back();
            res.push_back(sol);
            return;
        }
        
        helper(s, startIdx+1, num-1, sol+s.substr(startIdx,1)+".", res);
        if(s[startIdx] == '0') return;
        if(startIdx+1 < s.size())
            helper(s, startIdx+2, num-1, sol+s.substr(startIdx,2)+".", res);
        if(startIdx+2 < s.size()) {
            stringstream ss(s.substr(startIdx,3));
            int tmp;
            ss >> tmp;
            if(tmp <= 255)
                helper(s, startIdx+3, num-1, sol+s.substr(startIdx,3)+".", res);
        }
    }
};
