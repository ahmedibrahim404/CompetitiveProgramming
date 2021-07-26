#include <bits/stdc++.h>
typedef long long ll ;
using namespace std ;
const int N = 1e5+9;
const ll K = 1e18 + 1;
int n, q;
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


node *insert(node *root, ll idx, int val, ll nst = 0, ll nen = K){
    if (nst > idx || nen < idx) return root;
    if (nst == nen)return new node(val, root->l, root->r);
    ll m = (nst+nen)>>1;
    node *nl = insert(root->l, idx, val, nst, m);
    node *nr = insert(root->r, idx, val, m+1, nen);
    return new node(nl->val + nr->val, nl, nr);
}

int query(node *root, ll l, ll r, ll nst = 0, ll nen = K){
    if (nst > r || nen < l)return 0;
    if (nst >= l && nen <= r)return root->val;
    ll m = (nen+nst)>>1;
    return query(root->l, l, r, nst, m) + query(root->r, l, r, m+1, nen);
}


node *roots[2*100000 + 5];
node *EMPTY = new node;


int main(){
    scanf("%d%d",&q,&n);
    for (int i = 0; i <= q; i++) roots[i] = EMPTY;
    for(int i=0;i<n;i++) lst[i]=0;
    int idx=1;
    for (int i = 1; i <= q; i++){
        int t;scanf("%d", &t);
        if(t==1){
            roots[idx] = insert(roots[idx-1], lst[a], 1);
        } else {
            printf("%d\n", query(roots[idx-1], k+1, K));
        }
    }
}
