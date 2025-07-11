#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkPrimeFrequency(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        for (auto &pair : freq)
        {
            if (isPrime(pair.second))
            {
                return true;
            }
        }

        return false;
    }

private:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5, 4};
    cout << "Test 1: " << (sol.checkPrimeFrequency(nums1) ? "true" : "false") << endl;
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << (sol.checkPrimeFrequency(nums2) ? "true" : "false") << endl;
    vector<int> nums3 = {2, 2, 2, 4, 4};
    cout << "Test 3: " << (sol.checkPrimeFrequency(nums3) ? "true" : "false") << endl;

    return 0;
}