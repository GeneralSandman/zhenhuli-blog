


# Count Primes

## Link

https://leetcode.com/problems/count-primes


## Description

Count the number of prime numbers less than a non-negative number, `n`.



**Example 1:**
            Input: n = 10    Output: 4    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.    

**Example 2:**
            Input: n = 0    Output: 0    

**Example 3:**
            Input: n = 1    Output: 0    



**Constraints:**

  * `0 <= n <= 5 * 106`


**Tags:** Hash Table, Math

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/count-primes


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};

int main() {
    Solution s;

    cout << s.countPrimes(0) << endl;
    cout << s.countPrimes(1) << endl;
    cout << s.countPrimes(2) << endl;
    cout << s.countPrimes(3) << endl;


    cout << s.countPrimes(10) << endl;


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
