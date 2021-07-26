#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const int N = 1e5 + 5;
int n;
int ns[N];
pi sg[4 * N];

void merge(pi &a, pi b, pi c){
    if(b.first > c.first)
        a = make_pair(b.first, max(b.second, c.first));
    else a = make_pair(c.first, max(b.first, c.second));
}


void build(int idx=0, int l=0, int r=n-1){

    if(l == r){
        sg[idx] = { ns[l], -1e9 };
        return;
    }

    int mid=(l+r)>>1;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid+1, r);

    merge(sg[idx], sg[idx+idx+1], sg[idx+idx+2]);

}

int ql, qr;
pi query(int idx=0, int l=0, int r=n-1){

    if(ql > r || l > qr) return {-1e9, -1e9};
    if(l >= ql && r <= qr) return sg[idx];

    int mid=(l+r)>> 1;
    pi lq = query(2*idx+1, l, mid);
    pi rq = query(2*idx+2, mid+1, r);

    pi nw;merge(nw, lq, rq);

    return { nw.first, nw.second };

}

void update(int idx=0, int l=0, int r=n-1){
    if(l == r && l == ql){
        sg[idx] = { qr, -1e9 };
        return;
    }

    int mid=(l+r)>>1;
    if(ql > mid) update(2 * idx + 2, mid+1, r);
    else update(2 * idx + 1, l, mid);

    merge(sg[idx], sg[idx+idx+1], sg[idx+idx+2]);

}


int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> ns[i];
    build();
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        if(c=='Q'){
            cin >> ql >> qr;
            ql--, qr--;
            pi ans=query();
            cout << ans.first + ans.second << "\n";
        } else {
            cin >> ql >> qr;
            ql--;
            update();
        }
    }
    return 0;
}
