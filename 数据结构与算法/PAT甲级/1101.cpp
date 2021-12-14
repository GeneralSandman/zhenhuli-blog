#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

void printVector(vector<int> &array)
{
    for (int i = 0; i < array.size(); i += 1)
    {
        if (i)
        {
            cout << " " << array[i];
        }
        else
        {
            cout << array[i];
        }
    }
    cout << endl;
}

int main()
{
    int nums = 0;
    vector<int> array;

    cin >> nums;
    for (int i = 0; i < nums; i += 1)
    {
        int tmp;
        cin >> tmp;
        array.push_back(tmp);
    }

    if (nums == 1)
    {
        cout << nums << endl;
        cout << array[0] << endl;
        return 0;
    }

    vector<int> indexLeftMax(nums, 0);

    vector<int> indexRightMin(nums, INT_MAX);

    for (int i = 1; i < nums; i += 1)
    {
        indexLeftMax[i] = max(array[i - 1], indexLeftMax[i - 1]);
    }

    for (int i = nums - 2; i >= 0; i -= 1)
    {
        indexRightMin[i] = min(array[i + 1], indexRightMin[i + 1]);
    }

    vector<int> result;

    for (int i = 0; i < nums; i += 1)
    {
        if (indexLeftMax[i] <= array[i] && array[i] <= indexRightMin[i])
        {
            result.push_back(array[i]);
        }
    }

    cout << result.size() << endl;
    printVector(result);

    return 0;
}

