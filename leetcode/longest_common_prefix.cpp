// https://leetcode.com/problems/longest-common-prefix/

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = "";
        for(int i = 0; i < strs[0].length(); i++)
        {
            for(int k = 1; k < strs.size(); k++)
            {
                if(strs[0][i] != strs[k][i])
                {
                    return prefix;
                }
            }
            prefix = prefix + strs[0][i];
        }
        return prefix;    
    }
};
