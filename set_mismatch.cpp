#include <vector>
using namespace std;
class Solution
{
public:
    /*Input: nums = [1,2,2,4]
    Output: [2,3]*/
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                result.push_back(nums[i]);
                result.push_back(nums[i] + 1);
                break;
            }
        }
        return result;
    }
};