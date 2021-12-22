#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> values;
        char preSignal;
        preSignal = '+';

        int num = 0;
        for(int i=0;i<s.size();i+=1) {
            char c = s[i];

            if(' ' == c && i!=s.size()-1) {
                continue;
            }

            if('0'<=c && c<='9') {
                num = num*10 + int(c-'0');
                if(i!=s.size()-1) {
                    continue;
                }
            }

            switch(preSignal) {
                case '+':
                    values.push_back(num);
                    num = 0;
                    break;
                case '-':
                    values.push_back(-num);
                    num = 0;
                    break;
                case '*':
                    values.back() = values.back() * num;
                    num = 0;
                    break;
                case '/':
                    values.back() = values.back() / num;
                    num = 0;
                    break;
            }

            preSignal = c;
        }

        return accumulate(values.begin(), values.end(), 0);
    }
};

int main() {
    Solution s;

    cout << s.calculate(string(" 3/2 ")) << endl;

    return 0;
}
