#include <bits/stdc++.h>
using namespace std;
long long N, K, Q, lv = 1, nl = 1, x, y;
vector <long long> level;
long long parent(long long u)
{
    return (long long)ceil((u-1)/(double)(K));
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>Q;
    while (lv <= N)
    {
        level.push_back(lv);
        nl *= K;
        lv += nl;
    }
    for (int i = 0; i < Q; i++)
    {
        long long ans = 0;
        cin>>x>>y;
        long long lx = lower_bound(level.begin(), level.end(), x) - level.begin();
        long long ly = lower_bound(level.begin(), level.end(), y) - level.begin();
        //cout<<lx<<" "<<ly<<"\n";
        long long pa = x, pb = y;
        if (lx < ly)
        {
            for (int i = 0; i < ly-lx; i++)
            {
                pb = parent(pb);
                ans += 1;
            }
        }
        else if (lx > ly)
        {
            for (int i = 0; i < lx-ly; i++)
            {
                pa = parent(pa);
                ans += 1;
            }
        }
        while (pa != pb)
        {
            pa = parent(pa);
            pb = parent(pb);
            ans += 2;
        }
        cout<<ans<<"\n";
    }
}
