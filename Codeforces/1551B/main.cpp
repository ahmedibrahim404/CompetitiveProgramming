#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        int arr[n+1];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);


        map<pair<int,int>,int>mp;
        map<int,int>freq;
        vector<pair<int,int> >v;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            if(freq[arr[i]]>k)continue;
            v.push_back({arr[i],i});
        }
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-(v.size()%k);i++) mp[v[i]]=(i%k)+1;
        for(int i=0;i<n;i++)
            cout<<mp[{arr[i],i}]<<' ';
        cout<<endl;


    }
    return 0;
}
