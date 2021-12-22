#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,map<string,double>> graph;
        // build graph
        for(int i =0;i<equations.size();i+=1) {
            auto a = equations[i][0];
            auto b = equations[i][1];
            auto value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1/value;
        }

        vector<double> result;

        for(auto query:queries) {
            map<string, bool> visited;
            result.push_back(helper(graph, query[0], query[1], visited));
        }

        return result;
    }

    double helper(map<string,map<string,double >> &graph, string from, string to, map<string, bool> &visited) {
        if(from == to) {
            return 1;
        }

        // 没找到这个节点
        auto nextIter = graph.find(from);
        if (nextIter == graph.end()) {
            return -1;
        }

        auto nextNodes= nextIter->second;
        for(auto nextNode: nextNodes) {
            double result = helper(graph, nextNode->first, to, visited);
            if (result != -1) {
                
            }
        }

        return -1;

    }
};

int main() {
    Solution s;

    return 0;
}
