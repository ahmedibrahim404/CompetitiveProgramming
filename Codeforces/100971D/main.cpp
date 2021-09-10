#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;

const int N = 1 << 18 + 1;
int n;
int lg[N];
int sp[18][N];
int arr[N];
void init(){
    lg[0]=-1;
    for(int i=0;i<n;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = i;
    }
}

void buildSP(){

    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<(j-1))<= n;i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];
            sp[j][i] = arr[a] > arr[b] ? a : b;
        }
    }

}

int getMax(int st, int en){
    if(st > en) return st;
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];
    return arr[a] > arr[b] ? a : b;
}



vpi ns;
vector<int> v;
int main(){
    scanf("%d",&n);ns=vpi(n);int mx=0;map<int, int> mp;
    for(int i=0;i<n;i++){
        scanf("%d%d",&ns[i].first, &ns[i].second);
        v.push_back(ns[i].first);mx=max(mx, ns[i].second);
        mp[ ns[i].second ] = i;
    }
    sort(v.begin(), v.end());

    for(auto pi: ns){
        int fir=pi.first, sec=pi.second;
        int idx=lower_bound(v.begin(), v.end(), fir)-v.begin();
        arr[idx]=sec;
    }

    init();
    buildSP();
    int ans[n];for(int i=0;i<n;i++) ans[i]=-1;
    for(int i=0;i<n;i++){

        int st=0, en=1000000000;
        int pos = ns[i].first, val=ns[i].second;
        if(val == mx) continue;

        while(en >= st){


            int mid=(st+en)/2;

            int idx1=lower_bound(v.begin(), v.end(), pos-mid)-v.begin();
            int idx2=lower_bound(v.begin(), v.end(), pos+mid)-v.begin();
            if(idx2 == v.size() || v[idx2] > pos + mid) idx2--;
            int mx=getMax(idx1, idx2);

            if(arr[ mx ] > val) en=mid-1, ans[i] = arr[mx];
            else st=mid+1;

        }

    }

    for(int i=0;i<n;i++){
        if(ans[i] != -1) ans[i] = mp[ ans[i] ]+1;
        printf("%d ", ans[i]);
    }

    return 0;
}
