#include <iostream>

using namespace std;

/**

    Approach 1

    LCA ( Lower Common Ancestor )
    we need to
    1- implement euler tower (  E  ) size(E)=2*N-1
        => traverse through tree (dfs) and print all nodes ( even in duplicated )
    2- get level of nodes ( L ) where L[i] = level of E[i]
        when L[i]=0 it's higher than L[i]=3 ( not lower ) and vice versa
    3- first occurrence of each node ( H[i] )

    from euler tower =>> [
        if as following
            1 2 1 3 5 3 6 8 6 (9) 6 3 7 10 (12) 10
            if you draw the tree you will notice that LCA(9, 12) =3
            which appears as ( smallest value ) between 9 AND 12
            LCA => smallest value(level) between both ( RMQ )
    ]

    find lca of u, v at the tree rooted at r
//    int a = LCA(r,u);
//    int b = LCA(r,v);
//    int c = LCA(u,v);
//
//    if(a==b) re c
//    else if(b == c) re a
//    else re b




**/
const int MAX=200000+3;
int L[2*MAX-1], E[2*MAX-1], H[MAX];


int main(){

    // dfs and save values for L, E, H;
    /**
        LCA(p, g) =
        H[p]
        H[q]
        run rmq
        index = rmq(H[p], H[q], L)
        RES IS => E[index]
    **/

    return 0;
}
