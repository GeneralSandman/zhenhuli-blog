#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n==0) {
            return result;
        }
        if(n==1) {
            return {{1}};
        }
        vector<int> currentPath;
        dfs(n, k, 1, currentPath, result);
        return result;
    }

    void dfs(int n, int k, int index, vector<int> &currentPath, vector<vector<int>>& result) {
        if(currentPath.size() == k) {
            result.push_back(currentPath);
            return;
        }
        if(n < index) {
            return;
        }

        dfs(n, k, index+1, currentPath, result);

        currentPath.push_back(index);
        dfs(n, k, index+1, currentPath, result);
        // 不需要删除
        // 因为是传值，不是传引用，
        // 要是 currentPath 是引用的话，就需要删除
        // 如果不用引用 会频繁的创建空间 超时
        currentPath.erase(--currentPath.end());
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,2};

    auto result = s.combine(20, 16);
    cout << "--" << endl;
    cout << result.size() << endl;
    // for(auto array: result) {
    //     for(auto t: array) {
    //         cout << t << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
