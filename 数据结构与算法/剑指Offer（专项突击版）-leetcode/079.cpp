#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        if(nums.empty()) {
            return result;
        }
        vector<int> currentPath;
        dfs(nums, 0, currentPath, result);
        return result;
    }

    void dfs(vector<int>& nums, int index, vector<int> currentPath, vector<vector<int>>& result) {
        if(nums.size() == index) {
            result.push_back(currentPath);
            return;
        }

        dfs(nums, index+1, currentPath, result);

        currentPath.push_back(nums[index]);
        dfs(nums, index+1, currentPath, result);
        // 不需要删除
        // 因为是传值，不是传引用，
        // 要是 currentPath 是引用的话，就需要删除
        // currentPath.erase(--currentPath.end());
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,2};

    auto result = s.subsets(nums);
    cout << "--" << endl;
    for(auto array: result) {
        for(auto t: array) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
