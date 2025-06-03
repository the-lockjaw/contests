#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;

// Convert string to long long safely
long long stringToLL(const string &s)
{
    long long res = 0;
    for (char c : s)
    {
        if (c < '0' || c > '9')
            throw invalid_argument("Invalid digit in input string.");
        res = res * 10 + (c - '0');
        if (res < 0) // overflow check (optional here, since x <= 1e10)
            throw overflow_error("Number too large for 64-bit integer.");
    }
    return res;
}

vector<int> simpleSieve(int limit)
{
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; ++i)
        if (isPrime[i])
            primes.push_back(i);
    return primes;
}

vector<long long> segmentedSieve(long long low, long long high, const vector<int> &basePrimes)
{
    int size = high - low;
    vector<bool> isPrime(size, true);

    for (int p : basePrimes)
    {
        long long start = max(p * 1LL * p, ((low + p - 1) / p) * p);
        for (long long j = start; j < high; j += p)
            isPrime[j - low] = false;
    }

    vector<long long> primes;
    for (int i = 0; i < size; ++i)
        if (isPrime[i] && (low + i) > 1)
            primes.push_back(low + i);
    return primes;
}

long long sumOfLast3PrimesBelowX(const string &x_str)
{
    long long x = stringToLL(x_str);
    if (x <= 7)
        throw invalid_argument("x must be greater than 7 to find 3 primes below it.");

    int baseLimit = sqrt(x) + 1;
    vector<int> basePrimes = simpleSieve(baseLimit);

    long long window = 1000000; // size of the range to check below x
    long long low = max(2LL, x - window);
    long long high = x;

    vector<long long> primes = segmentedSieve(low, high, basePrimes);

    if (primes.size() < 3)
        throw runtime_error("Not enough primes found. Increase window size.");

    return primes[primes.size() - 1] + primes[primes.size() - 2] + primes[primes.size() - 3];
}

int main()
{
    string x_str;
    cout << "Enter x (as string, up to 1e10): ";
    cin >> x_str;

    try
    {
        long long result = sumOfLast3PrimesBelowX(x_str);
        cout << "Sum of the 3 largest primes less than " << x_str << " is: " << result << endl;
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
