


# 3Sum

## Link

https://leetcode.com/problems/3sum


## Description

Given an integer array nums, return all the triplets `[nums[i], nums[j],
nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] +
nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.



**Example 1:**
            Input: nums = [-1,0,1,2,-1,-4]    Output: [[-1,-1,2],[-1,0,1]]    

**Example 2:**
            Input: nums = []    Output: []    

**Example 3:**
            Input: nums = [0]    Output: []    



**Constraints:**

  * `0 <= nums.length <= 3000`
  * `-105 <= nums[i] <= 105`


**Tags:** Array, Two Pointers

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/3sum


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> threeSum(vector<int> &num)
    {

        vector<vector<int>> res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++)
        {

            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back)
            {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else
                {
                    vector<int> triplet = {num[i], num[front], num[back]};
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1])
                        front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2])
                        back--;
                }
            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }

        return res;
    }
};

class Solution2
{
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> res;

        sort(num.begin(), num.end());
        auto last = unique(num.begin(), num.end());
        num.erase(last, num.end());

        for (int i = 0; i < num.size(); i++)
        {

            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back)
            {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else
                {
                    vector<int> triplet = {num[i], num[front], num[back]};
                    res.push_back(triplet);
                }
            }

        }

        return res;
    }
};

int main()
{
    Solution s;

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
