#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        vector<string> M{"", "M", "MM", "MMM"};
        vector<string> D{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return M[num/1000] + D[num/100%10] + X[num/10%10] + X[num%10];
    }
};

int main() {
    Solution s;

    return 0;
}
