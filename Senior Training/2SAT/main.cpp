#include <iostream>

using namespace std;

/**
    Implication Table
        A -> B
        if B happens then A may have happened
        if B doesn't happen, A haven't happened
        [[ conclusion : if A is true, B is true
            if A is false, B maybe true or false
        ]]

    (A) -> B -> C -> D -> E -> (F)

    so, if we put A=false, F=true, then we have no restrictions on C, D, and E


    Conjuction (AND), Disjunction (OR)

    CNF = (OR) AND (OR) AND (OR)
    EX: (A or B) and (!B or C) and (C or !D)


    (A or B)
    if A is 0, B must be 1
    if B is 0, A must be 1
    if A or B is 1, No conditions on the other var

    so we have here 2 implications!!!
        if !A -> B
        if !B -> A

    one clause (A or B) is converted into 2 edges on the graph!


    => Suppose we have variable X
    if we have path from x to !x
        if( x is true, then !x must be true ( Implication table ) which is impossible )
        if( x is false, then !x has two options
    Summary: x must be false

    if we have path from !x to x, then x must be true


    if we have both pathes??? No answer ,,FAILS!

    A xor B is equivalent to => ((A or B) and (!A or !B))

**/

vector<vector<int>> adj; // total #nodes = 2*n
void addEdge(int a, int b){
    adj[a].push_back(b);
}

int not(int x){
    return x^1;
}

void addOR(int a, int b){
    addEdge(not(a), b);
    addEdge(not(b), a);
}

void addXOR(int a, int b){
    addOR(a, b);
    addOR(not(a), not(b));
}

void addXNOR(int a, int b){
    addOR(not(a), b);
    addOR(a, not(b));
}

void addImplication(int a, int b){
    addOR(not(a), b);
}

int main(){
    return 0;
}
