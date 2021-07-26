#include<bits/stdc++.h>

using namespace std;
const int MAX=200000+3;
int n,m, q;
string str[MAX];
int cum[MAX];
map<string, int> mp;

int getMid(int s, int e) { return s + (e -s)/2; }


int sum(int *st, int ss, int se, int qs, int qe, int si){
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = getMid(ss, se);
    return sum(st, ss, mid, qs, qe, 2*si+1) +
        sum(st, mid+1, se, qs, qe, 2*si+2);
}

void update(int *st, int ss, int se, int i, int diff, int si){
    if (i < ss || i > se)
        return;

    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        update(st, ss, mid, i, diff, 2*si + 1);
        update(st, mid+1, se, i, diff, 2*si + 2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val){
    int diff = new_val - arr[i];
    arr[i] = new_val;
    update(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe){
    return sum(st, 0, n-1, qs, qe, 0);
}

int stcreate(int arr[], int ss, int se, int *st, int si){
    if (ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] = stcreate(arr, ss, mid, st, si*2+1) + stcreate(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int *makeST(int arr[], int n){
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    stcreate(arr, 0, n-1, st, 0);
    return st;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> q;
    for(int i=0;i<n;i++) cin >> str[i];
    string strs;int cohol;
    for(int i=0;i<m;i++) {
        cin >> strs >> cohol;
        mp[strs]=cohol;
    }

    for(int i=0;i<n;i++){
        int coh=mp[ str[i] ];
        cum[i] = coh;
    }

    int* st = makeST(cum, n);

    string ty;
    int a, b, c;

    bool update;

    while(q--){
        cin >> a;
        if(a==2){
            cin >> b >> c;
            b--, c--;
            int ms=(c-b+1)*30;
            int sum=getSum(st, n, b, c);
            if(sum<=ms) cout << "NO\n";
            else cout << "YES\n";
        } else {
            cin >> b >> ty;
            b--;
            updateValue(cum, st, n, b, mp[ty]);
        }

    }

    return 0;
}
