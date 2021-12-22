#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() <=2) {
            return true;
        }


        vector<int> nodeColors(graph.size(), 0);
        // 0 未访问
        // -1 黑
        // 1 红

        // 还要考虑一下 有多个子图的情况

        for(int i=0;i<graph.size(); i+=1) {
            if(nodeColors[i] != 0) {
                continue;
            }
            auto result = helper(graph, nodeColors, i, -1);
            if(!result) {
                return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<int>>& graph, vector<int> &nodeColors, int node, int color) {
        if(nodeColors[node] != 0) {
            return nodeColors[node] == color;
        }
        nodeColors[node] = color;

        for(auto nextNode:graph[node]) {
            auto result = helper(graph, nodeColors, nextNode, -color);
            if (!result) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    return 0;
}
