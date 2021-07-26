#include<bits/stdc++.h>
using namespace std;

int T, n,m, ns[100000+9], ms[100000+9];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> ns[i];
            ms[i]=ns[i];
        }
        if(n==m){
            cout << "Richman" << endl;;
            continue;
        }

        sort(ms, ms+n);

        if(m == 0){
            if(ms[0] == 0) cout << "Impossible" << endl;
            else cout << ms[0]-1 << endl;
            continue;
        }

        for(int i=1;i<n;i++) ms[i] += ms[i-1];
        int took=m, cur=0;
        long long cnt=0;
        while(took){
            if(ms[took-1] > ns[cur]){
                cnt += ns[cur];
                took--;
                cur++;
            } else {
                cnt += ms[cur+took-1]-ms[cur-1];
                cur += took;
                took=0;
            }
        }
        cnt += ns[cur]-1;
        if(cnt < 0) cout << "Impossible" << endl;
        else cout << cnt << endl;


    }

    return 0;
}
