#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int cnt[30] = {0};
        bool zero=1;
        for(int i=0;i<n;i++){
            int num;cin >> num;
            zero &= (num==0);
            for(int j=0;j<30;j++){
                cnt[j] += (num>>j)&1;
            }
        }
        if(zero){
            for(int i=0;i<n;i++) cout << i+1 << " ";
            continue;
        }
        map<int, int> mp;
        int c=0;
        for(int i=0;i<30;i++){
            int num = cnt[i];
            if(!num) continue;
            c++;
            for(int j=1;j*j <= num;j++){
                if(num%j) continue;
                int fir = j, sec = num/j;
                if(mp.count(fir))mp[fir]++;else mp[fir]=1;
                if(fir != sec) if(mp.count(sec))mp[sec]++;else mp[sec]=1;
            }
        }
        for(auto it= mp.begin();it!=mp.end();it++){
            if(it->second == c) cout << it->first << " ";
        }
        cout << endl;

    }
    return 0;
}
