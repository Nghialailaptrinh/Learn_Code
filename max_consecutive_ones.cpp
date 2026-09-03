/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.*/


#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (int num : nums)
        {
            count[num]++;
        }

        int duplicate = 0;
        int missing = 0;
        for(int i = 1; i <= n; i++)
        {
            if (count[i] == 2)
            {
                duplicate = i;
            }
            else if (count[i] == 0)
            {
                missing = i;
            }
        }
        return {duplicate, missing};

    }
};