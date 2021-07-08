#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hashTable;

        for(int index = 0; index < s.size(); index++) {
            char a = s[index];
            char b = t[index];

            if(hashTable.end() != hashTable.find(a) && hashTable[a] != b) {
                return false;
            }
            hashTable[a] = b;
        }

        return true;

    }
};

class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {-1}, m2[256] = {-1}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};

int main() {
    Solution s;

    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    cout << s.isIsomorphic("badc", "baba") << endl;


    cout << "--------" << endl;
    Solution1 s1;

    cout << s1.isIsomorphic("egg", "add") << endl;
    cout << s1.isIsomorphic("foo", "bar") << endl;
    cout << s1.isIsomorphic("paper", "title") << endl;
    cout << s1.isIsomorphic("badc", "baba") << endl;


    return 0;
}
