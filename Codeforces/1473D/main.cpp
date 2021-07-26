#include <iostream>

using namespace std;
const int MAX=200000+3;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ns[n];
        string str;
        cin >> str;
        int p[n];
        int minP[n], maxP[n], minS[n], maxS[n];

        for(int i=0;i<n;i++) ns[i]=str[i]=='+'?1:-1;
        p[0]=0;
        for(int i=0;i<n;i++){
            if(i)p[i] = p[i-1];
            p[i] += ns[i];
        }

        minP[0] = min(p[0], 0);
        for (int i = 1; i < n; i++) {
            minP[i] = min(minP[i - 1], p[i]);
        }

        maxP[0] = max(p[0], 0);
        for (int i = 1; i < n; i++) {
            maxP[i] = max(maxP[i - 1], p[i]);
        }

        minS[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--){
            minS[i] = min(minS[i+1], p[i]);
        }

        maxS[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--){
            maxS[i] = max(maxS[i+1], p[i]);
        }

        while(m--){
            int a, b;
            cin >> a >> b;
            a--, b--;
            int sum=p[b]-(a?p[a-1]:0);

            if(a==0 && b == n-1){
                cout << "1\n";
                continue;

            }

            int mi=0, mx=0;


            if(b<n-1) mi=min(mi, minS[b+1]-sum), mx=max(mx, maxS[b+1]-sum);

            if(a) mx=max(mx, maxP[a-1]),  mi=min(mi, minP[a-1]);

            cout << mx-mi+1 << "\n";

        }




    }
    return 0;
}
