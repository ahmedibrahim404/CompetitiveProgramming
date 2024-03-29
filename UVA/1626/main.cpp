

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = (1 << 15);
const ll OO = 2ll * 1e8;

string x;
int mem[105][105];
int go(int l,int r)
{
    if(l > r)
        return 0;
    if(l == r)
        return 1;
    int &ret = mem[l][r];
    if(ret != -1)
        return ret;
    ret = OO;
    if(x[l] == '(' && x[r] == ')' || x[l] == '[' && x[r] == ']')
        ret = min(ret,go(l+1,r-1));
    for(int i=l; i<r; i++)
        ret = min(ret,go(l,i)+go(i+1,r));
    return ret;
}

vector<int> ad;

void go2(int l,int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        ad.pb(l);
        return;
    }

    for(int i=l; i<r; i++)
        if(mem[l][r] == go(l,i)+go(i+1,r))
        {
            go2(l,i);
            go2(i+1,r);
            return;
        }
    go2(l+1,r-1);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    getline(cin,x);
    while(T--){
        memset(mem,-1,sizeof mem);
        ad.clear();
        getline(cin,x);
        getline(cin,x);
        go(0,x.size()-1);
        go2(0,x.size()-1);
        sort(ad.begin(),ad.end());
        int r = 0;
        for(int i=0; i<x.size(); i++)
        {
            if(r < ad.size() && ad[r] == i)
            {
                r++;
                if(x[i] == ')' || x[i] == '(')
                    cout << "()";
                else
                    cout << "[]";
            }
            else
                cout << x[i];
        }
        cout << "\n";
        if(T)
            cout << "\n";
    }
    return 0;
}
