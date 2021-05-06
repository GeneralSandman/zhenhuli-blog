


# Longest Substring Without Repeating Characters

## Link

https://leetcode.com/problems/longest-substring-without-repeating-characters


## Description

Given a string `s`, find the length of the **longest substring** without
repeating characters.



**Example 1:**
            Input: s = "abcabcbb"    Output: 3    Explanation: The answer is "abc", with the length of 3.    

**Example 2:**
            Input: s = "bbbbb"    Output: 1    Explanation: The answer is "b", with the length of 1.    

**Example 3:**
            Input: s = "pwwkew"    Output: 3    Explanation: The answer is "wke", with the length of 3.    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.    

**Example 4:**
            Input: s = ""    Output: 0    



**Constraints:**

  * `0 <= s.length <= 5 * 104`
  * `s` consists of English letters, digits, symbols and spaces.


**Tags:** Hash Table, Two Pointers, String, Sliding Window

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/longest-substring-without-repeating-characters


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

```

#### ** Go **

``` go

package main

func main() {
	
}


```

#### ** Scala **

``` scala


object Solution {
    def maxDepth(root: TreeNode): Int = {
    }




    def main(args: Array[String]): Unit = {
   }
}

```

<!-- tabs:end -->
