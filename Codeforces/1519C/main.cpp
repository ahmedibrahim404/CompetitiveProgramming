#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;

vector<int> divs[N];

int main()
{
    for (int i = 1; i < N; i++)
    {
        for (int div = 1; div*div <= i; div++)
        {
            if (i%div == 0)
            {
                divs[i].push_back(div);
                if (i/div != div)
                    divs[i].push_back(i/div);
            }
        }
    }

    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        vector<vector<ll>> ns(n);
        vector<int> as(n);
        vector<ll> ans(n+1);
        vector<bool> vis(n+1);
        for (int i = 0; i < n; i++){
            scanf("%d",&as[i]);
            as[i]--;
        }
        for (int i = 0; i < n; i++){
            int s;
            scanf("%d",&s);
            ns[as[i]].push_back(s);
        }
        for (int i = 0; i < n; i++){
            sort(ns[i].begin(), ns[i].end(), greater<ll>());
            for (int j = 1; j < ns[i].size(); j++)
                ns[i][j] += ns[i][j-1];

        }
        for (int i = 0; i < n; i++){
            for (int j = ns[i].size()-1; j>=0; j--){
                for (auto& div: divs[j+1]){
                    if (!vis[div]){
                        vis[div] = 1;
                        ans[div] += ns[i][j];
                    }
                }
            }

            for (int j = ns[i].size() - 1; j >= 0; j--)
                for (auto& div: divs[j+1])
                    vis[div] = 0;
        }
        for (int i=1;i<=n;i++)
            printf("%lld ", ans[i]);
        printf("\n");
    }

    return 0;
}
