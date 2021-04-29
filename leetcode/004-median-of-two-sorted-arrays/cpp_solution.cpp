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
