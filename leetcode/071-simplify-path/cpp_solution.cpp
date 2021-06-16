#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);

        while (getline(ss, tmp, "/")) {
            cout << tmp << endl;
        }
    }
};
int main() {
    Solution s;
    s.simplifyPath("/1/2/3/4");
    return 0;
}
