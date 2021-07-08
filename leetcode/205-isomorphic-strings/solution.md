


# Isomorphic Strings

## Link

https://leetcode.com/problems/isomorphic-strings


## Description

Given two strings `s` and `t`, _determine if they are isomorphic_.

Two strings `s` and `t` are isomorphic if the characters in `s` can be
replaced to get `t`.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same
character, but a character may map to itself.



**Example 1:**
            Input: s = "egg", t = "add"    Output: true    

**Example 2:**
            Input: s = "foo", t = "bar"    Output: false    

**Example 3:**
            Input: s = "paper", t = "title"    Output: true    



**Constraints:**

  * `1 <= s.length <= 5 * 104`
  * `t.length == s.length`
  * `s` and `t` consist of any valid ascii character.


**Tags:** Hash Table

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/isomorphic-strings


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

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


```

#### ** Go **

``` go

this is just a code

```

#### ** Scala **

``` scala

this is just a code

```

<!-- tabs:end -->
