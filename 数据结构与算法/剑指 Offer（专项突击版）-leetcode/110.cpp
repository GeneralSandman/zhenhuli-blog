#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;

        helper(graph, result, path, 0);
        return result;
    }

    void helper(vector<vector<int>>& graph,vector<vector<int>>& result,vector<int> path, int nodeIndex) {

        path.push_back(nodeIndex);
        if(nodeIndex == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        for(auto next:graph[nodeIndex]) {
            helper(graph, result, path, next);
        }

    }
};

int main() {
    Solution s;

    return 0;
}
