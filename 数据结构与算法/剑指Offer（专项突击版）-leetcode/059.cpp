#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class KthLargest {
private:
    vector<int> data;
    int dataNum;

    // 最小堆，只存k个值，【0】就是第k大
    // 右边比左边大

    void addValue(int val) {
        if(dataNum > 0 && val <= data[0]) {
            // 比最小堆的最小值还小
            // 不需要往里边放了
            return;
        }

        data[0] = val;
        down(0);
        // for(auto t:data) {
        //     cout << t << endl;
        // }
    }

    void down(int index) {
        if(index >= data.size()) {
            return;
        }

        int leftNodeIndex = index * 2 + 1;
        int rightNodeIndex = index * 2 + 2;

        if(data[rightNodeIndex] < data[index]) {
            if(rightNodeIndex < data.size()) {
                swap(data[rightNodeIndex], data[index]);
                down(rightNodeIndex);
            }
        } else if (data[leftNodeIndex] < data[index]) {
            if(leftNodeIndex < data.size()) {
                swap(data[leftNodeIndex], data[index]);
                down(leftNodeIndex);
            }
        }
    }
public:
    KthLargest(int k, vector<int>& nums) {
        dataNum = 0;

        for(auto num:nums) {
            addValue(num);
        }
    }
    
    int add(int val) {
        addValue(val);
        return data[0];
    }


};

int main() {
    vector<int> init = {4,5,8,2};
    KthLargest s(3, init);
    cout << "---" << s.add(3) << endl;
    cout << "---" << s.add(5) << endl;
    cout << "---" << s.add(10) << endl;
    cout << "---" << s.add(9) << endl;
    cout << "---" << s.add(4) << endl;

    return 0;
}
