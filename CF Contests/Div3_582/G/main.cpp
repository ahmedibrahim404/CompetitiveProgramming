#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+15;

int t , n , k;

vector< pair<int , pair<int,int> > > v;
long long ans[N] , fat[N] , sz[N];

int fin(int x)
{
    if(fat[x]!=x)
        return fat[x] = fin(fat[x]);
    return x;
}
long long tot;

void unio(int a , int b)
{
    int aa = fin(a);
    int bb = fin(b);
    tot+=1ll*sz[aa]*sz[bb];
    sz[bb]+=sz[aa];
    sz[aa] =0;
    fat[aa] = bb;
}

int main() {
    for(int i = 0;i<N;i++)
        fat[i] = i , sz[i] = 1;
    cin>>n>>k;
    for(int i = 0;i<n-1;i++)
    {
        int t1 , t2 , t3;
        cin>>t1>>t2>>t3;
        v.push_back({ t3, {t1,t2}});
    }
    sort(v.begin() , v.end());

    vector< pair<int,int> > q;
    for(int i = 0;i<k;i++)
    {
        int t1;
        cin>>t1;
        q.push_back( {t1 ,i} );
    }
    sort(q.begin() , q.end());

    int j = 0;
    for(int i = 0;i<k;i++)
    {
        while( j<n-1 && v[j].first<=q[i].first)
        {
            unio( v[j].second.first , v[j].second.second);
            j++;
        }
        ans[ q[i].second ] = tot;
    }

    for(int i = 0;i<k;i++)
        cout<<ans[i]<<" ";
    return 0;
}
