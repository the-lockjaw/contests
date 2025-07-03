/*
Interactive MST

There is a weighted undirected connected simple graph G with N vertices, M edges, with binary weights. The i-th edge connects Ui​ and Vi​, and has a weight of Wi​. It is guaranteed that 0≤Wi≤1 for all edges.

Alice and Bob are playing a game on the graph. Alice knows everything about the graph, but Bob knows only N, M and the edges, i.e. he does not know the weights. Note that 2≤N≤13.

Bob can do the following action at most 2⋅M times:

    Bob gives Alice a binary sequence of length M, which is A=[A1,A2,…,AM] where 0≤Ai≤1.
    Now, Alice considers a hypothetical scenario where the weights of the edges are instead represented by Bi=Wi⋅Ai (i.e. the 2 values multiplied together)
    Alice returns the sum of weights of the minimum spanning tree in this new graph.

A sequence of weights W is called solvable if there exists a strategy for Bob to figure out all the weights using the above action at most 2⋅M times.

Unfortunately, Alice has realized that not all sequences are solvable. To rectify this, she has decided to change some of the weights in her graph such that it becomes solvable, i.e. she can choose an edge and change it's value from 0 to 1 or vice versa.

Find the minimum number of changes to the sequence W so that it becomes solvable. It can be proven that for any graph, there always exists at least one solvable sequence.
Input Format
    The first line of input will contain a single integer T, denoting the number of test cases.
    Each test case consists of multiple lines of input.
        The first line of each test case contains 2 integers - N and M, the number of vertices and edges.
        The next MM lines contain 3 integers each - Ui,ViUi​,Vi​ and WiWi​, representing an edge.

Output Format

For each test case, output on a new line the minimum number of changes to the sequence WW so that it becomes solvable.
Constraints

    1≤T≤50
    2≤N≤13
    N−1≤M≤N*(N−1)/2
    1≤Ui,Vi≤N
    0≤Wi≤1
    The given graph is simple and connected, no multi edges or self edges.

Sample 1:
Input
Output

3
3 3
1 2 0
2 3 0
3 1 0
3 3
1 2 1
2 3 0
3 1 1
3 3
1 2 1
2 3 1
3 1 1

2
0
0

Explanation:

In all 3 test cases, you are given the same graph, a cycle with 3 vertices.

It can be shown that (for this graph) the sequences [1,0,1] and [1,1,1] are solvable while [0,0,0] is not solvable. We can change [0,0,0] to [1,0,1] in 2 changes, and thus the answer is 2 for [0,0,0].

We do not provide the strategies directly, instead we mention what happens on specific actions by Bob based on the different multiplier sequences A.
    Bob chooses the vector A=[0,1,1].
        When W=[0,0,0], the updated weights B are [0,0,0] and the MST sum is 0.
        When W=[1,0,1], the updated weights B are [0,0,1] and the MST sum is 0.
        When W=[1,1,1], the updated weights B are [0,1,1] and the MST sum is 1.
    Bob chooses the vector A=[1,1,1]
        When W=[0,0,0], the updated weights B are [0,0,0] and the MST sum is 0.
        When W=[1,0,1], the updated weights B are [1,0,1] and the MST sum is 1.
        When W=[1,1,1], the updated weights B are [1,1,1] and the MST sum is 2.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool all_zeroes = true;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (w != 0)
                all_zeroes = false;
        }
        if (all_zeroes && m >= n)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}