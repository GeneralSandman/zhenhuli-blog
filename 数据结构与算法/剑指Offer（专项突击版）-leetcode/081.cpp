#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==0) {
            return result;
        }

        vector<int> currentPath;
        dfs(candidates, target, 0, currentPath, result);
        return result;
    }

    void dfs(vector<int>& candidates, int target, int index, vector<int> &currentPath, vector<vector<int>>& result) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            result.push_back(currentPath);
            return;
        }

        if(candidates.size() <= index) {
            return;
        }

        dfs(candidates, target, index+1, currentPath, result);

        // 如果下边这三行不注释 会有什么现象
        // currentPath.push_back(candidates[index]);
        // dfs(candidates, target-candidates[index], index+1, currentPath, result);
        // currentPath.erase(--currentPath.end());

        currentPath.push_back(candidates[index]);
        dfs(candidates, target-candidates[index], index, currentPath, result);
        currentPath.erase(--currentPath.end());
        // 不需要删除
        // 因为是传值，不是传引用，
        // 要是 currentPath 是引用的话，就需要删除
        // 如果不用引用 会频繁的创建空间 超时
        // currentPath.erase(--currentPath.end());
    }
};

int main() {
    Solution s;

    vector<int> nums = {2,3,5};

    auto result = s.combinationSum(nums, 8);
    cout << "--" << endl;
    for(auto array: result) {
        for(auto t: array) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
