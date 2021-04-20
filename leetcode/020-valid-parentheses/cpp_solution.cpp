#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> loop;

        for(int i=0;i<s.length();i+=1){
             if (loop.size() == 0) {
                 loop.push(s[i]);
                 continue;
             }

             if (helper(loop.top(), s[i])) {
                 loop.pop();
             } else {
                 loop.push(s[i]);
             }
        }

        return loop.size() == 0;
    }

    bool helper(char o, char n) {
        if ((o=='[' && n == ']') || (o=='{' && n == '}') || (o=='(' && n == ')')) {
            return true;
        }
        return false;
    }
};

int main() {

    Solution s;

    vector<string> a = {"()", "()[]{}", "{[]}", "[}", "({[)"};

    for(int i = 0;i<a.size();i++) {
        std::cout << s.isValid(a[i]) << std::endl;
    }

    return 0;
}
