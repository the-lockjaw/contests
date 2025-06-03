/*
You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.
Return the minimum number of swaps required to rearrange nums into this sorted order.
A swap is defined as exchanging the values at two distinct positions in the array.

Example 1:
Input: nums = [37,100]
Output: 1
Explanation:
    Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
    Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
    Thus, the minimum number of swaps required to rearrange nums is 1.

Example 2:
Input: nums = [22,14,33,7]
Output: 0
Explanation:
    Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
    Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
    Thus, the minimum number of swaps required to rearrange nums is 0.

Example 3:
Input: nums = [18,43,34,16]
Output: 2
Explanation:
    Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
    Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
    Thus, the minimum number of swaps required to rearrange nums is 2.

aints:
    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    nums consists of distinct positive integers.
*/

#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int rem = num % 10;
        sum += rem;
        num /= 10;
    }
    return sum;
}

bool custom_compare(pair<int, int> &a, pair<int, int> &b, vector<int> &nums)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return nums[a.second] < nums[b.second];
}

int minSwaps(vector<int> &nums)
{
    vector<pair<int, int>> x;
    for (int i = 0; i < nums.size(); i++)
    {
        x.push_back(make_pair(sum_of_digits(nums[i]), i));
    }
    sort(x.begin(), x.end(), [&](pair<int, int> &a, pair<int, int> &b)
         { return custom_compare(a, b, nums); });
    int n = x.size();
    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] || x[i].second == i)
            continue;

        int cycle_len = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = true;
            j = x[j].second;
            cycle_len++;
        }

        if (cycle_len > 0)
            swaps += (cycle_len - 1);
    }

    return swaps;
}

int main()
{
    vector<int> q = {22, 14, 33, 7};
    int ans = minSwaps(q);
    cout << "Answer = " << ans << endl;
}