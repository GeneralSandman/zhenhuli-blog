#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> evals;

        for(int i =0; i< tokens.size();i+=1) {
            
            string token = tokens[i];
            int val = 0;
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                val = atoi(tokens[i].c_str());
                evals.push(val);
                continue;
            }

            int b = evals.top();evals.pop();
            int a = evals.top();evals.pop();

            if (token == "+") {
                val = a + b;
            } else if (token == "-") {
                val = a - b;
            } else if (token == "*") {
                val = a * b;
            } else if (token == "/") {
                val = a / b;
            }
            evals.push(val);
        }


        return evals.top();
    }
};

int main() {
    Solution s;

    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << s.evalRPN(tokens) << endl;
    return 0;
}
