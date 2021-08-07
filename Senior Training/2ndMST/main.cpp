#include <iostream>

using namespace std;


/**

    Sort the edges in O(ElogE), then find a MST using Kruskal in O(E).
    For each edge e not already in the MST, temporarily add it to the MST, creating a cycle.
    Find the edge k with maximal weight in the cycle that is not equal to e.
    Remove k temporarily, creating a new spanning tree.
    Compute the weight difference δ=weight(e)−weight(k), and remember it together with the changed edge.
    Repeat step 2 for all other edges, and return the spanning tree with the smallest weight difference to the MST.
    The time complexity of the algorithm depends on how we compute the ks, which are the maximum weight edges in step 2 of this algorithm. One way to compute them efficiently in O(ElogV) is to transform the problem into a Lowest Common Ancestor (LCA) problem.

    We will preprocess the LCA by rooting the MST and will also compute the maximum edge weights for each node on the paths to their ancestors. This can be done using Binary Lifting for LCA.

    The final time complexity of this approach is O(ElogV).

**/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
