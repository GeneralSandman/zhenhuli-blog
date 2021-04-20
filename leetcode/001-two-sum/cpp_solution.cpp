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
