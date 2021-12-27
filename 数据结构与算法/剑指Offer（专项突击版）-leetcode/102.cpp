#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty()) {
            return 0;
        }

        int result = 0;
        dfs(nums, target, 0, result);
        return result;
    }

    void dfs(vector<int>& nums, int target, int index, int &result) {
        if(index >= nums.size()) {
            if(target == 0) {
                result+=1;
            }
            return;
        }

        dfs(nums,target-nums[index], index+1, result);
        dfs(nums,target+nums[index], index+1, result);
    }
};

int main() {
    Solution s;

    vector<int> nums = {1};
    int target = 1;
    cout << s.findTargetSumWays(nums, target) << endl;

    return 0;
}
