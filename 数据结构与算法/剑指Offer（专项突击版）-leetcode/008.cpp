#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        int begin = 0;
        int end  = 0;

        int result = INT_MAX;
        int sum = 0;

        while(end < nums.size()) {
            sum += nums[end];

            if(sum >= target) {
                result = min(result, end - begin + 1);

                // begin 往前走
                while(begin <= end) {
                    if((sum - nums[begin]) >= target) {
                        sum = sum - nums[begin];
                        begin += 1;
                        result = min(result, end - begin + 1);
                    } else {
                        break;
                    }
                }
            }

            end += 1;
        }

        if(result == INT_MAX) {
            return 0;
        }
        return result;

    }
};

int main() {
    Solution s;

    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    cout << s.minSubArrayLen(target, nums) << endl;

    return 0;
}
