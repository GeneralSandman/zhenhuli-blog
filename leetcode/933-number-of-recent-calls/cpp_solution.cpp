#include <iostream>
#include <vector>
#include <map>
#include <queue>


using namespace std;

class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        myQueue.push(t);

        int begin = t - 3000;

        while (myQueue.front() < begin) {
            myQueue.pop();
        }
        return myQueue.size();
    }

private:
    queue<int> myQueue;
    
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(1);
    int param_2 = obj->ping(100);
    int param_3 = obj->ping(3001);
    int param_4 = obj->ping(3002);

    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    return 0;
}
