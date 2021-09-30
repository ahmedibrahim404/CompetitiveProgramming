#include<bits/stdc++.h>

using namespace std;
const int MAX=200000+3;

struct segmentTree {

    vector<int> tree;
    vector<int> arr;
    int treeSz;
    int sz;
    int init(int n, vector<int> vi){
        sz=ceil ( 1.0 * log(n)/log(2) ), treeSz = 1<<(sz+1), sz=n;
        tree=vector<int>(treeSz);arr=vi;
        return build(0, sz-1, 1);
    }

    int build(int st, int en, int p){
        if(st==en) return tree[p]=arr[st];
        tree[p] = build(st, (st+en)/2, 2*p) + build((st+en)/2 + 1, en, 2*p+1);
//        cout << p << " " << tree[p] << "\n";
        return tree[p];
    }

    int sum(int st, int en, int p, int l, int r){
        if(st >= l && en <= r) return tree[p];
        if(st > r || en < l) return 0;
        return sum(st, (st+en)/2, 2*p, l, r) + sum(1+(st+en)/2, en, 2*p+1, l, r);
    }

    int sum(int l, int r){
        return sum(0, sz-1, 1, l, r);
    }

    void update(int st, int en, int p, int idx, int val){

        if(st==en){
            tree[p] = val;
            return;
        }

        if(idx > (st+en)/2){
            update(1+(st+en)/2, en, 2*p+1, idx, val);
        } else {
            update(st, (st+en)/2, 2*p, idx, val);
        }

        tree[p] = tree[2*p+1] + tree[2*p];

    }

    void update(int idx, int val){
        update(0, sz-1, 1, idx, val);
    }

};

int n;
int main(){
    scanf("%d",&n);
    vector<int> ns=vector<int>(n);
    for(int i=0;i<n;i++)scanf("%d",&ns[i]);
    segmentTree st;
    st.init(n, ns);

    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            cout << st.sum(b, c) << "\n";
        } else {
            st.update(b, c);
        }
    }

    return 0;
}
