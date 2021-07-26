#include<bits/stdc++.h>
using namespace std;
const int MAX=15+3;
int T, N, ps[MAX];

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0;i<N;i++) cin >> ps[i];
        sort(ps, ps+N);
        int time=300, pt=0, tot=0;
        for(int i=0;i<N;i++){
            if(time - ps[i] >= 0){
                tot ++;
                pt += ps[i]+(i?ps[i-1]:0);
                time -= ps[i];
            }
            if(i)ps[i] += ps[i-1];
        }
        cout << tot << " " << pt << "\n";
    }
    return 0;
}
