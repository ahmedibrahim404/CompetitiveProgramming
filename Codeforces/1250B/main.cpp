#include<bits/stdc++.h>
using namespace std;
vector<int> cnt;

int cost(int k){
    int l=0, r=cnt.size()-1;
    int ans=0;
    while(r > l){
        if(cnt[r] + cnt[l] <= k) ans++, l++, r--;
        else if(cnt[r] <= k) ans++, r--;
        else return -1;
    }
    if(l == r){
        if(cnt[l] <= k)ans++; else return -1;
    }
    return ans * k;
}

int main(){
    int n, k;
    scanf("%d%d",&n,&k);

    map<int, int> mp;
    for(int i=0;i<n;i++){
        int no;scanf("%d",&no);
        if(mp.count(no)) mp[no]++;
        else mp[no]=1;
    }

    for(auto it=mp.begin(); it!=mp.end();it++){
        cnt.push_back(it->second);
    }

    sort(cnt.begin(), cnt.end());

    int st = cnt[cnt.size()-1];
    int en = n;

    for(int i=0;i<1000;i++){
        int m1 = st + (en-st)/3, m2 = m1 + (en-st)/3;
        if(cost(m1) < cost(m2)) en = m2;
        else st = m1;
    }

    int mn=2e9;
    for(int k=st-1000;k<=st+1000;k++){
        if(k <= 0) continue;
        int cs=cost(k);
        if(cs != -1)
        mn = min(cs, mn);
    }

    cout << mn << endl;

    return 0;
}
