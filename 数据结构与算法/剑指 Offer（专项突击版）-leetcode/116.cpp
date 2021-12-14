#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int circleNum = 0;

        if (isConnected.size() == 0 || isConnected[0].size() == 0)
        {
            return 0;
        }

        int cityNum = isConnected.size();
        map<int, bool> visited;
        for (int i = 0; i < cityNum; i += 1)
        {
            if (visited.find(i) == visited.end())
            {
                helper(isConnected, visited, cityNum, i);
                circleNum += 1;
            }
        }

        return circleNum;
    }

    int helper(vector<vector<int>> &isConnected, map<int, bool> &visited, int cityNum, int i)
    {
        queue<int> accessQueue;
        accessQueue.push(i);

        while (accessQueue.size() != 0)
        {
            int tmp = accessQueue.front();
            accessQueue.pop();
            visited[tmp] = true;


            for (int n = 0; n < cityNum; n += 1)
            {
                if (isConnected[tmp][n] == 0) {
                    continue;
                }
                if (visited.find(n) != visited.end())
                {
                    continue;
                }

                accessQueue.push(n);
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;

    return 0;
}
