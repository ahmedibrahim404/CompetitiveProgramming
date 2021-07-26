#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=100+1;
int t, n, m;
ll ns[MAX][MAX];

vector<ll> vi;

// will be the median of sorted list

ll getmin(){

    int sz=vi.size();
    ll sum=0;
    for(int i=0;i<sz;i++){
        sum += abs(vi[i]-vi[sz/2]);
    }


    return sum;

}

int main(){
    scanf("%d",&t);
    while(t--){


        scanf("%d%d",&n,&m);

        ll cost=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%lld",&ns[i][j]);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                vi.resize(0);
                vi.push_back(ns[i][j]);
                if(j!=m-j-1) vi.push_back(ns[i][m-j-1]);
                if(i!=n-i-1) vi.push_back(ns[n-i-1][j]);
                if(i!=n-i-1 && j!=m-j-1) vi.push_back(ns[n-i-1][m-j-1]);
                sort(vi.begin(), vi.end());

                ll add=getmin();
                cost += add;
                ns[i][j]=ns[i][m-j-1]=ns[n-i-1][j]=ns[n-i-1][m-j-1]=1LL;


            }

        }

        printf("%lld\n", cost);


    }
    return 0;
}
