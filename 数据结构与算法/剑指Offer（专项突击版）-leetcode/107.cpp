#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> matrixDistances;
        if (mat.size() == 0 || mat[0].size() == 0)
        {
            return matrixDistances;
        }

        int width = mat.size();
        int height = mat[0].size();

        for (int i = 0; i < width; i += 1)
        {
            matrixDistances.push_back(vector<int>(height, INT_MAX));
        }

        queue<pair<int, int>> accessQueue;

        for (int i = 0; i < width; i += 1)
        {
            for (int j = 0; j < height; j += 1)
            {
                if (mat[i][j] == 0)
                {
                    matrixDistances[i][j] = 0;
                    accessQueue.push(make_pair(i, j));
                }
            }
        }

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!accessQueue.empty())
        {
            auto point = accessQueue.front();
            accessQueue.pop();

            for (int i = 0; i < 4; i += 1)
            {
                int nextPoint_x = point.first + directions[i][0];
                int nextPoint_y = point.second + directions[i][1];
                if (0 <= nextPoint_x && nextPoint_x < width &&
                    0 <= nextPoint_y && nextPoint_y < height &&
                    matrixDistances[nextPoint_x][nextPoint_y] > matrixDistances[point.first][point.second] + 1)
                {
                    matrixDistances[nextPoint_x][nextPoint_y] = matrixDistances[point.first][point.second] + 1;
                    accessQueue.push(make_pair(nextPoint_x,nextPoint_y));
                }
            }
        }

        return matrixDistances;
    }
};

int main()
{
    Solution s;

    return 0;
}
