#include <bits/stdc++.h>
typedef long long ll ;
using namespace std ;
const int N = 1e5+9, W = 1e5;
int n, m;
struct node;
extern node* EMPTY;

struct node{
    node *l, *r;
    int val;

    node(){
        val = 0;
        l = r = this;
    }

    node(int val, node *l = EMPTY, node *r = EMPTY){
        this->val = val;
        this->l = l;
        this->r = r;
    }

};


node *insert(node *root, int idx, int val, int nst = 0, int nen = W){
    if (nst > idx || nen < idx)return root;
    if (nst == nen)return new node(val, root->l, root->r);
    int m = (nst+nen)>>1;
    node *nl = insert(root->l, idx, val, nst, m);
    node *nr = insert(root->r, idx, val, m+1, nen);
    return new node(max(nl->val, nr->val), nl, nr);
}

int query(node *root, int l, int r, int nst = 0, int nen = W){
    if (nst > r || nen < l)return 0;
    if (nst >= l && nen <= r)return root->val;
    int m = (nen+nst)>>1;
    return max(query(root->l, l, r, nst, m), query(root->r, l, r, m+1, nen));
}


node *roots[N];
node *EMPTY = new node;

int main(){
    scanf("%d%d", &n, &m);
    int u, v, c;
    for (int i = 0; i <= n; i++)roots[i] = EMPTY;
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &c);
        int nw = query(roots[u], 0, c-1) + 1;
        roots[v] = insert(roots[v], c, nw);
    }


    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, query(roots[i], 0, W));
    printf("%d\n", ans);

}
