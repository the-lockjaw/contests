/*
Mex Tree (Min)

You have a tree with N vertices. A tree is a connected undirected acyclic graph on N vertices with N−1 edges.

You want to assign distinct labels to the vertices of the tree. You will choose a permutation P of the integers [0,N−1] and then assign the vertex X a label of PX​.

Define MEX(S) for a set S, as the minimum non-negative integer not present in S. For example, MEX({1,0,2,2,4})=3 and MEX({1})=0.

Define f(u,v) as MEX({PX1​​,PX2​​,PX3​​,…,PXK​​}) where X1,X2,…,XK​ are the vertices on the unique simple path from u to v (including u and v themselves, so X1=uX1​=u, XK=vXK​=v).

Define score of the tree as ∑X=1N∑Y=XNf(X,Y), i.e. the sum of f over all pairs of vertices.

You must find the minimum possible value of score if you can suitably choose the permutation P.
Input Format
    The first line of input will contain a single integer T, denoting the number of test cases.
    Each test case consists of multiple lines of input.
        The first line of each test case contains a single integer N.
        The next N−1 lines contain 22 integers each, u and v - representing an edge in the tree.

Output Format
For each test case, output on a new line the minimum possible score.
Constraints
    1≤T≤50
    3≤N≤2000
    1≤u,v≤N
    The set of input edges define a tree
    The sum of N over all test cases does not exceed 20002000.

Sample 1:
Input
Output

2
4
1 2
2 3
3 4
4
1 2
1 3
1 4

7
5

Explanation:

Test Case 1 : We choose P=[1,2,3,0]. The calculations are as follows:

    f(1,1)=0
    f(1,2)=0
    f(1,3)=0
    f(1,4)=4
    f(2,2)=0
    f(2,3)=0
    f(2,4)=1
    f(3,3)=0
    f(3,4)=1
    f(4,4)=1

Adding the values, we get 4+1+1+1=7. It can be proven a smaller score is impossible.
*/