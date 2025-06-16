#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int arraySize;
        ll budget;
        cin >> arraySize >> budget;

        vector<ll> numbers(arraySize);
        for (int idx = 0; idx < arraySize; idx++)
        {
            cin >> numbers[idx];
        }

        ll totalBits = 0;
        for (int idx = 0; idx < arraySize; idx++)
        {
            totalBits += __builtin_popcountll(numbers[idx]);
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> minHeap;

        for (int idx = 0; idx < arraySize; idx++)
        {
            ll currentNum = numbers[idx];
            ll nextPowerOfTwo = currentNum | (currentNum + 1);
            ll cost = nextPowerOfTwo - currentNum;

            if (cost > 0)
            {
                minHeap.push(make_pair(cost, idx));
            }
        }

        ll improvements = 0;

        while (!minHeap.empty() && minHeap.top().first <= budget)
        {
            ll cost = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();

            budget -= cost;
            improvements++;
            numbers[index] += cost;

            ll updatedNum = numbers[index];
            ll nextTarget = updatedNum | (updatedNum + 1);
            ll newCost = nextTarget - updatedNum;

            if (newCost > 0)
            {
                minHeap.push(make_pair(newCost, index));
            }
        }

        cout << totalBits + improvements << "\n";
    }

    return 0;
}