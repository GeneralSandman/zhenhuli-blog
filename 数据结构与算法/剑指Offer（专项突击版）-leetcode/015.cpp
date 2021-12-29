#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if(s.empty() || p.empty()) {
            return result;
        }

        vector<int> hashTable(26,0);
        for(auto t:p) {
            hashTable[int(t-'a')] ++;
        }

        int begin = 0;
        int end = p.size() - 1;



        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
