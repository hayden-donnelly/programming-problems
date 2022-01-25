using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for(int x = 0; x < nums.size(); x++)
        {
            for(int y = 0; y < nums.size(); y++)
            {
                if(x == y)
                {
                    continue;
                }
                if(nums[x] + nums[y] == target)
                {
                    vector<int> solution {x, y};
                    return solution;
                }
            }
        }
        // This should never be run because there should always be a solution.
        vector<int> solution {0, 0};
        return solution;
    }
};