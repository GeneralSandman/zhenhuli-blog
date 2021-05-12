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
