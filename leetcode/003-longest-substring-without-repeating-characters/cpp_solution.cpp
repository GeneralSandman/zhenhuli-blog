#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashTable(256, -1);

        int start = -1;
        int result = 0;
        for(int i=0;i<s.size();i+=1) {

            if (hashTable[s[i]] > start) {
                start = hashTable[s[i]];
            }
            hashTable[s[i]] = i;
            result = max(result, i - start);
        }

        return result;
    }
};


int main() {
    Solution s;

    cout << s.lengthOfLongestSubstring("a") << endl;
    cout << s.lengthOfLongestSubstring("ab") << endl;
    cout << s.lengthOfLongestSubstring("aba") << endl;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    cout << s.lengthOfLongestSubstring("abcdefg") << endl;
    return 0;
}