


# Median of Two Sorted Arrays

## Link

https://leetcode.com/problems/median-of-two-sorted-arrays


## Description

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively,
return **the median** of the two sorted arrays.



**Example 1:**
            Input: nums1 = [1,3], nums2 = [2]    Output: 2.00000    Explanation: merged array = [1,2,3] and median is 2.    

**Example 2:**
            Input: nums1 = [1,2], nums2 = [3,4]    Output: 2.50000    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.    

**Example 3:**
            Input: nums1 = [0,0], nums2 = [0,0]    Output: 0.00000    

**Example 4:**
            Input: nums1 = [], nums2 = [1]    Output: 1.00000    

**Example 5:**
            Input: nums1 = [2], nums2 = []    Output: 2.00000    



**Constraints:**

  * `nums1.length == m`
  * `nums2.length == n`
  * `0 <= m <= 1000`
  * `0 <= n <= 1000`
  * `1 <= m + n <= 2000`
  * `-106 <= nums1[i], nums2[i] <= 106`



**Follow up:** The overall run time complexity should be `O(log (m+n))`.


**Tags:** Array, Binary Search, Divide and Conquer

**Difficulty:** Hard

## 思路

[title]: https://leetcode.com/problems/median-of-two-sorted-arrays


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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0;

        while (index1<nums1.size() || index2 < nums2.size()) {
            
        }
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1,3,5,7,9};
    vector<int> nums2 = {2,4,6,8,10};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
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
