#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) {
            return s.size();
        }


        vector<int> hashTable(256,-1);
        
        int begin = 0;
        int end = 0;
        int result = 0;

        while(end < s.size()) {
            if(hashTable[s[end]] == -1) {
                // 前边没有重复的
            } else {
                // 有重复的了 往前走一步
                // 这个地方要往前走，可能有后退的情况
                begin = max(hashTable[s[end]] + 1, begin);

                // cout << "after update " << begin << endl;
            }
            hashTable[s[end]] = end;
            result = max(result, end - begin + 1);
            end += 1;
        }


        return result;
    }
};



int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    return 0;
}
