#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
int n;
vpi ns;
vi mx;
map<pi, int> mp;
int main(){
    scanf("%d",&n);
    ns=vpi(n);
    mx=vi(n);
    int cost, ress;
    for(int i=0;i<n;i++){
        scanf("%d%d",&ns[i].first, &ns[i].second);
        if(i==n-1){
            cost=ns[i].first;
            ress=ns[i].second;
        }
        mp[ns[i]]=i;
    }
    sort(ns.begin(), ns.end());
    int curmx=0;
    for(int i=0;i<n;i++){
        if(ns[i].second >= ns[curmx].second) curmx=i;
        mx[i]=curmx;
    }


    int curc=0, curr=1;
    bool found=1;
    vi ans;
    while(curr < cost){

        int idx=lower_bound(ns.begin(), ns.end(), pi(curr, 0))-ns.begin();
        pi p=ns[idx];
        if(p.first>curr) idx--;

        while(idx+1<n && ns[idx].first==ns[idx+1].first){
            idx++;
        }

        if(idx >= 0) p=ns[idx];
        else {
            found=0;
            break;
        }

        int till=mx[idx];

        if(ns[till].second <= curr){
            found=0;
            break;
        }

        curc=ns[till].first;
        curr=ns[till].second;
        ans.push_back(mp[ {curc, curr} ]);

    }




    if(!found){
         printf("No such luck\n");
         return 0;
    }


    int sz=ans.size();
    printf("%d\n", sz+1);
    for(int i=0;i<sz;i++){
        printf("%d ", ans[i]+1);
    }

    printf("%d\n", mp[ { cost, ress } ]+1);




    return 0;
}
