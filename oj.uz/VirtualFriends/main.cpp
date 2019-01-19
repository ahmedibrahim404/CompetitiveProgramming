#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct disjoin_set {

    map<string, string>  parent;
    map<string, int> rank;
    int forests;

    disjoin_set(int n){}



    string find_set(string x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    void link(string x, string y){

        if(rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
		rank[y] += rank[x];

    }

    int union_sets(string x, string y){

        x = find_set(x), y=find_set(y);

        if(x!=y)
            link(x, y);


        return max(rank[x], rank[y]);

    }

};

int t, n;
string n1, n2;
int main()
{
    cin >> t;
    while(t--){

        cin >> n;

        disjoin_set ds(2*n);

        while(n--){


            cin >> n1 >> n2;

            if(ds.parent.count(n1) == 0){

                ds.parent[n1] = n1;
                ds.rank[n1] = 1;

            }


            if(ds.parent.count(n2) == 0){

                ds.parent[n2] = n2;
                ds.rank[n2] = 1;

            }

            cout << ds.union_sets(n1, n2) << endl;

        }

    }
    return 0;
}
