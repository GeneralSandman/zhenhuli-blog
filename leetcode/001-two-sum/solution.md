


# Two Sum

## Link

https://leetcode.com/problems/two-sum


## Description

Given an array of integers `nums` and an integer `target`, return _indices of
the two numbers such that they add up to`target`_.

You may assume that each input would have **_exactly_ one solution**, and you
may not use the _same_ element twice.

You can return the answer in any order.



**Example 1:**
            Input: nums = [2,7,11,15], target = 9    Output: [0,1]    Output: Because nums[0] + nums[1] == 9, we return [0, 1].    

**Example 2:**
            Input: nums = [3,2,4], target = 6    Output: [1,2]    

**Example 3:**
            Input: nums = [3,3], target = 6    Output: [0,1]    



**Constraints:**

  * `2 <= nums.length <= 103`
  * `-109 <= nums[i] <= 109`
  * `-109 <= target <= 109`
  * **Only one valid answer exists.**


**Tags:** Array, Hash Table

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/two-sum


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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() <= 1) {
            return result;
        }

        map<int, int> hashTable;
        for(int i=0;i<nums.size();i+=1) {
            hashTable[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i+=1) {
            if (hashTable.end() != hashTable.find(target-nums[i]) && hashTable[target-nums[i]] != i) {
                result.push_back(i);
                result.push_back(hashTable[target-nums[i]]);
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}


```

#### ** Go **

``` go

package main

func twoSum(nums []int, target int) []int {
	var result []int
    if len(nums) < 2 {
		return result
	}

	hashTable := make(map[int]int)
	for i:=0;i<len(nums);i+=1{
		hashTable[nums[i]] = i
	}

	for i:=0;i<len(nums);i+=1{
		if v,ok:=hashTable[target-nums[i]]; ok && v != i {
			result = append(result, i)
			result = append(result, v)
			break;
		}
	}


	return result
}

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
