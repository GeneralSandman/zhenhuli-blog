#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int width = matrix.size();
        if(width == 0) {
            return 0;
        }
        int height = matrix[0].size();
        if(height == 0) {
            return 0;
        }

        int result = 0;
        vector<int> tmp (height,0);
        vector<vector<int>> maxLength (width, tmp);

        for(int i=0;i<width;i+=1) {
            for(int j=0;j<height;j+=1) {
                if(result == 0) {
                    helperBFS(matrix, maxLength, result, i, j);
                }
            }
        }

        return result;
    }

    void helperBFS(vector<vector<int>>& matrix, vector<vector<int>>& maxLength, int &result, int i, int j) {


        int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(int x=0;x<4;x+=1) {
            int nextNode_i = i + directions[x][0];
            int nextNode_j = j + directions[x][1];

            if(0<=nextNode_i && nextNode_i<matrix.size() &&
                0<=nextNode_j && nextNode_j<matrix[0].size()) {
                    helperBFS(matrix, maxLength, result, i, j);
                }
        }

    }
};

int main() {
    Solution s;

    return 0;
}
