// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> openingParantheses;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                openingParantheses.push(s[i]);
            }
            else
            {
                if(openingParantheses.empty())
                {
                    return false;
                }
                char currentParanthese = openingParantheses.top();
                openingParantheses.pop();
                if(currentParanthese == '(' && s[i] == ')'
                    || currentParanthese == '{' && s[i] == '}'
                    || currentParanthese == '[' && s[i] == ']')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return openingParantheses.empty();
    }
};
