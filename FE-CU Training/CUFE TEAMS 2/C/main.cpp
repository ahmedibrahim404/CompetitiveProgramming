#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 3e5 + 5;

int arr[MAXN];

struct segmentTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = 1;
        while(size < n) size <<= 1;
        tree.resize(size << 1);
    }

    void update(int i, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = val;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            update(i, val, 2 * x + 1, lx, mid);
        else
            update(i, val, 2 * x + 2, mid, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void update(int i, int val) {
        update(i, val, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return tree[x];

        int mid = (lx + rx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, mid);
        int s2 = sum(l, r, 2 * x + 2, mid, rx);

        return s1 + s2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main()
{
    int t, n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        map<int, int> mapo;
        for (int i = 0; i < n; i++)
            scanf("%d",&arr[i]),
            mapo[arr[i]] = i;

        for (int i = 0; i < n; i++){
            scanf("%d",&arr[i]),
            arr[i] = mapo[arr[i]];
        }

        segmentTree st;
        st.init(n);

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += st.sum(arr[i], n);
            st.update(arr[i], 1);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
