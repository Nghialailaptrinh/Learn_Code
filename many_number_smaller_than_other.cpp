#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        // pair = {giá trị, số lần xuất hiện}
        vector<pair<int, int>> values;

        // Đếm số lần xuất hiện
        for (int num : nums) {
            bool found = false;

            for (auto& p : values) {
                if (p.first == num) {
                    p.second++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                values.push_back({num, 1});
            }
        }

        // Sort theo giá trị (first)
        sort(values.begin(), values.end());

        vector<int> result(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (const auto& p : values) {
                if (p.first < nums[i]) {
                    count += p.second;
                } 
            }
            result[i] = count;
        }

        return result;
    }
};