#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
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
        vector<vector<int> > maxLength (width, tmp);

        for(int i=0;i<width;i+=1) {
            for(int j=0;j<height;j+=1) {
                result = max(result, helperBFS(matrix, maxLength, i, j));
            }
        }


        // for(int i=0;i<width;i+=1) {
        //     for(int j=0;j<height;j+=1) {
        //         cout << maxLength[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return result;
    }

    int helperBFS(vector<vector<int> >& matrix, vector<vector<int> >& maxLength, int i, int j) {
        if (maxLength[i][j] != 0) {
            return maxLength[i][j];
        }

        maxLength[i][j] =1 ;

        int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int x=0;x<4;x+=1) {
            int nextNode_i = i + directions[x][0];
            int nextNode_j = j + directions[x][1];

            if(0<=nextNode_i && nextNode_i<matrix.size() &&
                0<=nextNode_j && nextNode_j<matrix[0].size()) {
                
                if (matrix[nextNode_i][nextNode_j] > matrix[i][j]) {
                    maxLength[i][j] = max(maxLength[i][j], helperBFS(matrix, maxLength, nextNode_i, nextNode_j) + 1);
                }
                
            }
        }

        return maxLength[i][j];
    }
};

int main() {
    Solution s;

    vector<vector<int> > matrix;

    matrix.push_back(vector<int>{9,9,4});
    matrix.push_back(vector<int>{6,6,8});
    matrix.push_back(vector<int>{2,1,1});

    cout << s.longestIncreasingPath(matrix);

    

    return 0;
}
