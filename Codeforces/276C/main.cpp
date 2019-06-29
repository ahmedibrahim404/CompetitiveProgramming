#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n, q, a, b;
int ns[200000+9];
vector<ll> D;



void update(vector<ll>& D, int l, int r){
    D[l] += 1;
    D[r + 1] -= 1;
}

void getArray(vector<ll>& A, vector<ll>& D){
    for (int i = 0; i < A.size(); i++) {
        if (i == 0)
            A[i] = D[i];
        else
            A[i] = D[i] + A[i - 1];
    }
}

int main(){

    scanf("%d %d", &n, &q);
    vector<ll> A=vector<ll>(n);
    for(int i=0;i<n;i++) scanf("%d", &ns[i]);
    D=vector<ll>(n + 1);
    for(int i=0;i<q;i++){
        scanf("%d %d", &a, &b);
        a--;
        b--;
        update(D, a, b);
    }

    getArray(A, D);

    sort(ns, ns+n);
    sort(A.begin(), A.end());

    ll ans=0;
    for(int i=0;i<n;i++){
        ans += ns[i]*A[i];
    }

    printf("%lld", ans);

    return 0;
}
