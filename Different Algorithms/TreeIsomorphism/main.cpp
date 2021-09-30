#include <iostream>

using namespace std;

// Okay, suppose that we have 2 trees [ not graphs ] and we wanna make sure that both are similar

/***

    Two ways

    first way => tree canonical using dfs
    second way => using bfs called shrinking


***/

/**

        1
    2       3
4       5       6

       5
    1       4
3       2       6

these both trees are alike
how can we do that???

some function called tree canonical form
    => but you must know your tree root [
        what if not?????
            you can get your tree centers
            it's 1 or 2
            so at most you will try 4 canonical to compare
    ]

    canonical function transfers the tree into parentheses =>>
    [

        so each leaf is ()

        if some node has 2 leafs then its representation is ( () () )

                        1
                    2       3
                4       5

            ( (() ()) () )

            and we will sort them to compare the trees

    ]

**/

string treeCanonical(int node=0, int par=-1){

    vector<string> vs;
    for(int &child: ns[node]){
        if(child==par) continue;
        vs.push_back(treeCanonical(child, node));
    }

    sort(vs.begin(), vs.end());
    string rep="";
    rep += "(";
    for(int i=0;i<vs.size();i++) rep += vs[i];
    rep += ")";

    return rep;
}


/**
// now we considered the root is 0
    what if we don't know??
    get the tree centers =>>
        [


            two ways
                1- => [
                    get tree diameter and if length is even ( 2*x ) it has 1 center => [ x+1 ]
                        if length is odd ( 2*x + 1 ) it has 2 centers [ x+1, x+2 ]
                ]

                2- => [
                    explained below (( shrinking ))
                ]


        ]
**/


int getCenter(){

    /**
        bfs from any random node(v1)and get the furthest node let's call it v2
        bfs from (v2) and get the furthest node call it (v3)
        then (v2) --- (v3) is the tree diameter

        traverse back using parent array from v3 to v2
            get nodes numbered [x+1] if length is even
            of nodes numbered [x+1, x+2] if length is odd

        they are the centers
    **/

    /**
        can be done also using shrinking
    **/

    return 0;

}



/**
    shrinking
    start from leaves of the tree level by level using bfs
        append each leaf to its parent and consider it as a leaf
            keep going till there is ( 1 or 2 ) remaining leafs
                one of them will be the tree center ( or both )

**/
string getNodeCanoincalForm(int v, vector< vector<string> > &subCan)	// we could use hashing for a better performance
{
	string nodeRep = "(";
	sort( all(subCan[v]) );
	rep(i, subCan[v])
		nodeRep += subCan[v][i];
	nodeRep += ")";

	return nodeRep;
}

/*
 * Tree shrinking algorithm. Each time leaves shrink toward their parents.
 */
string treeCanoincalForm()	// assumes tree not forest
{
	int n = sz(adjLst);

	// Prepare level one nodes: the leaves
	queue<int> LeafNodes;
	vector<int> deg(n, -1);
	int remNodes = n;

	rep(i, adjLst) {
		if(sz(adjLst[i]) <= 1)
			LeafNodes.push(i);
		else
			deg[i] = sz(adjLst[i]);
	}

	vector< vector<string> > subCan(n);

	while(remNodes > 2)	// bfs-like
	{
		int sz = sz(LeafNodes);
		while(sz--)	// level by level
		{
			int v = LeafNodes.front();			LeafNodes.pop();

			string nodeRep = getNodeCanoincalForm(v, subCan);

			rep(j, adjLst[v]) {
				int to = adjLst[v][j];
				subCan[to].push_back(nodeRep);
				if(--deg[to] == 1)
					LeafNodes.push(to);
			}
			--remNodes;
		}
	}

	// what remains are tree centers
	int v1 = LeafNodes.front();			LeafNodes.pop();
	int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

    /**
        v1 and v2 are tree centers
    **/

	string str1 = getNodeCanoincalForm(v1, subCan);
	string str2 = v2 == -1? "" : getNodeCanoincalForm(v2, subCan);

	if(v2 == -1)	// only 1 node
		return str1;

	// 2 nodes. try 2nd as child of first and reverse
	subCan[v1].push_back(str2);
	subCan[v2].push_back(str1);

	return min(getNodeCanoincalForm(v1, subCan), getNodeCanoincalForm(v2, subCan));
}





int main(){
    return 0;
}
