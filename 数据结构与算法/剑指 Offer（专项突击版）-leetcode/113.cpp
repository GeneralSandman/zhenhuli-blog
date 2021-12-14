#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> indirections;
        map<int,bool> visited;
        map<int,vector<int>> dependences;

        for(int i=0;i<numCourses;i+=1) {
            indirections[i] = 0;
        }

        for(int i=0;i<prerequisites.size();i+=1) {
            indirections[prerequisites[i][0]] += 1;
            dependences[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> zeroIndirectionCourses;

        for(auto i = indirections.begin();i != indirections.end();i++){
            if (i->second == 0) {
                zeroIndirectionCourses.push(i->first);
            }
        }

        vector<int> result;

        while(!zeroIndirectionCourses.empty()) {
            auto front = zeroIndirectionCourses.front();
            zeroIndirectionCourses.pop();

            result.push_back(front);

            for(auto next:dependences[front]) {
                indirections[next] -= 1;

                if(indirections[next] == 0) {
                    zeroIndirectionCourses.push(next);
                }
            }
        }

        if (result.size() != numCourses) {
            return vector<int>();
        }

        return result;

    }
};

int main() {
    Solution s;

    return 0;
}
