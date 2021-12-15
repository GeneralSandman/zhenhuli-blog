#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int>> Grid;
    int Width;
    int Height;
    vector<vector<int>> AccessHashTable;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        Grid = grid;
        Width = grid.size();
        Height = grid[0].size();
        for (int x=0;x<Width;x+=1) {
            AccessHashTable.push_back(vector<int> (Height));
        }

        int maxArea = 0;

        for(int x=0;x<Width;x+=1) {
            for(int y=0;y<Height;y+=1) {
                if (Grid[x][y] == 1 && AccessHashTable[x][y] == 0) {
                    maxArea = max(maxArea, findArea(x,y));
                }
            }
        }

        return maxArea;
    }

    int findArea(int x, int y) {

        int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int area = 0;
        queue<pair<int,int >> accessQueue;
        accessQueue.push(make_pair(x,y));

        while(!accessQueue.empty()) {
            auto point = accessQueue.front();
            accessQueue.pop();
            if (AccessHashTable[point.first][point.second] == 1) {
                continue;
            }
            area += 1;
            AccessHashTable[point.first][point.second] = 1;

            // 四个方向
            for(int i=0;i<4;i+=1) {
                pair<int,int> nextPoint;
                int nextPoint_x, nextPoint_y;
                nextPoint_x = point.first + directions[i][0];
                nextPoint_y = point.second + directions[i][1];

                if( 0<= nextPoint_x && nextPoint_x < Width &&
                    0<= nextPoint_y && nextPoint_y < Height &&
                    Grid[nextPoint_x][nextPoint_y] == 1 &&
                    AccessHashTable[nextPoint_x][nextPoint_y] == 0
                ) {
                    accessQueue.push(make_pair(nextPoint_x,nextPoint_y));
                }
            }
        }

        return area;
    }
};

int main() {
    Solution s;

    return 0;
}
