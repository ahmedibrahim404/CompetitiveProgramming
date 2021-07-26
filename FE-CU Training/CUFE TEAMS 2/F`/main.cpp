#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100020;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

vector<pair<ll,ll> > v,d,tv;
vector<pair<int,ll> > s;

int pos(ll x,ll y)
{
    if(x>0 && y>=0) return 1;
    if(x<=0 && y>0) return 2;
    if(x<0 && y<=0) return 3;
    if(x>=0 && y<0) return 4;
    return 0;
}

bool cmp(const pair<int,ll> l,const pair<int,ll> r)
{
    return
    pos(tv[l.first].first,tv[l.first].second)==pos(tv[r.first].first,tv[r.first].second)?
    tv[l.first].second*tv[r.first].first<tv[r.first].second*tv[l.first].first:
    pos(tv[l.first].first,tv[l.first].second)<pos(tv[r.first].first,tv[r.first].second);
}

bool cmp2(const pair<ll,ll>& l,const pair<ll,ll>& r)
{
    return pos(l.first,l.second)==pos(r.first,r.second)?l.second*r.first<r.second*l.first:pos(l.first,l.second)<pos(r.first,r.second);
}

int main(void)
{
    int n=read();
    double PI=3.14159265358979323846;

    v.resize(n);
    d.resize(n);
    s.resize(n);
    tv.resize(n);

    ll sum=0;

    for(int i=0;i<n;i++) scanf("%ld %ld %ld",&v[i].first,&v[i].second,&s[i].second),s[i].first=i,sum+=s[i].second;

    ll ans=sum;
    for(int x=0;x<n;x++)
    {
        for(int i=0;i<n;i++) tv[i].first=v[i].first-v[x].first,tv[i].second=v[i].second-v[x].second;
        sort(s.begin(),s.end(),cmp);

        vector<pair<ll,double> > tts(3*n+10);
        for(int i=1;i<n;i++)
        {
            tts[i].first=s[i].second;
            if(tv[s[i].first].second==0)
            {
                if(tv[s[i].first].first>0) tts[i].second=0.0;
                else tts[i].second=PI;
            }
            else tts[i].second=atan2(tv[s[i].first].second,tv[s[i].first].first);

            if(tv[s[i].first].second<0) tts[i].second+=PI*2;
            tts[i+n-1].first=tts[i].first;
            tts[i+2*n-2].first=tts[i].first;
            tts[i+n-1].second=tts[i].second+PI*2;
            tts[i+2*n-2].second=tts[i].second+PI*4;
        }

        for(int i=1;i<=3*n-3;i++){
            tts[i].first+=tts[i-1].first;
        }
        ll ts=0;
        int r=1;
        for(int l=1;l<n;l++)
        {
            while(tts[r+1].second-tts[l].second<=PI)
            {
                r++;
            }
            ll a=tts[r].first-tts[l].first;
            ll b=sum-s[0].second-s[l].second-a;

            ans=min(ans,abs(a-b));
        }
    }

    printf("%lld",ans);

    return 0;
}
